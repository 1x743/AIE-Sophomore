#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

// Utility function to create file paths
string create_output_path(const string& input_path, const string& suffix) {
    size_t dot_pos = input_path.find_last_of('.');
    if (dot_pos == string::npos) return input_path + suffix;
    return input_path.substr(0, dot_pos) + suffix;
}

// Function to check contour features
bool contour_features(vector<Point> contour) {
    double area = contourArea(contour);
    if (area < 100) return false;

    double perimeter = arcLength(contour, true);
    double circularity = 4 * CV_PI * area / (perimeter * perimeter);

    return circularity > 0.6;
}

int main(int argc, char** argv) {
    // Check arguments
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <ImagePath>" << endl;
        return -1;
    }

    // Setup output paths
    string input_path = argv[1];
    string threshold_output = create_output_path(input_path, "_threshold.png");
    string edge_output = create_output_path(input_path, "_edge.png");
    string cropped_output = create_output_path(input_path, "_cropped.png");
    string polar_output = create_output_path(input_path, "_polar.png");
    string hist_output = create_output_path(input_path, "_histogram.png");

    // Read the input image
    Mat frame = imread(input_path);
    if (frame.empty()) {
        cout << "Error: Could not read the image: " << input_path << endl;
        return -1;
    }
    // Ensure values are explicitly float
    Point2f center(static_cast<float>(frame.cols) / 2.0f, static_cast<float>(frame.rows) / 2.0f);
    float angle = 40.0f;  // Explicitly float
    float scaleFactor = 1.0f;   // Renamed to avoid conflict

    // Compute rotation matrix
    Mat rotation_matrix = getRotationMatrix2D(center, angle, scaleFactor);
    Mat rotated_frame;

    // Apply affine transformation
    warpAffine(frame, rotated_frame, rotation_matrix, frame.size());


    // Use rotated image for further processing
    frame = rotated_frame;

    // Initialize variables
    Mat dst_image1, src_gray, dst, grad;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    // Image preprocessing
    GaussianBlur(frame, dst_image1, Size(5, 5), 0, 0);
    cvtColor(dst_image1, src_gray, COLOR_BGR2GRAY);

    // Compute gradients
    Mat grad_x, grad_y, abs_grad_x, abs_grad_y;
    Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);

    // Combine gradients and threshold
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    threshold(grad, dst, 5, 255, THRESH_BINARY);
    //imwrite(threshold_output, dst);
    cout << "Saved threshold image to: " << threshold_output << endl;

    // Find contours
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Process contours
    vector<vector<Point>> contours_poly(contours.size());
    vector<vector<Point>> contours_cycle;
    vector<Rect> boundRect(contours.size());
    int valid_contours = 0;

    for (size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(contours[i], contours_poly[valid_contours], 1, true);
        if (contours_poly[valid_contours].size() > 5 && contour_features(contours_poly[valid_contours])) {
            contours_cycle.push_back(contours_poly[valid_contours]);
            boundRect[valid_contours] = boundingRect(contours_poly[valid_contours]);
            valid_contours++;
        }
    }

    // Find largest contour
    int max_area = 0;
    int max_idx = -1;
    for (int i = 0; i < valid_contours; i++) {
        int area = boundRect[i].width * boundRect[i].height;
        if (area > max_area) {
            max_area = area;
            max_idx = i;
        }
    }

    if (max_idx >= 0) {
        // Draw and save the contour detection
        Mat drawing = Mat::zeros(dst.size(), CV_8UC3);
        rectangle(frame, boundRect[max_idx], Scalar(0, 255, 0), 2);
        //imwrite(edge_output, frame);
        cout << "Saved edge detection to: " << edge_output << endl;

        // Crop and save the region of interest
        Mat crop;
        Mat(frame, boundRect[max_idx]).copyTo(crop);
        imwrite(cropped_output, crop);
        cout << "Saved cropped image to: " << cropped_output << endl;

        // Perform polar transform
        Mat polar_image;
        Point2f center(crop.cols / 2.0f, crop.rows / 2.0f);
        linearPolar(crop, polar_image, center, max(crop.rows, crop.cols) / 2, WARP_FILL_OUTLIERS);
        imwrite(polar_output, polar_image);
        cout << "Saved polar transform to: " << polar_output << endl;

        // Process edge region
        Mat imgEdge;
        Mat(polar_image, Rect(polar_image.cols - 90, 0, 90, polar_image.rows)).copyTo(imgEdge);
        rotate(imgEdge, imgEdge, ROTATE_90_COUNTERCLOCKWISE);
        cvtColor(imgEdge, imgEdge, COLOR_BGR2GRAY);

        // Calculate histogram
        const int MAX_HIST_SIZE = 1000;
        vector<int> histogram(MAX_HIST_SIZE, 0);
        int max_val = 0;

        for (int i = 0; i < imgEdge.cols; i++) {
            int sum = 0;
            for (int j = 0; j < imgEdge.rows; j++) {
                sum += imgEdge.at<uchar>(j, i);
            }
            if (i < MAX_HIST_SIZE) {
                histogram[i] = sum;
                max_val = max(max_val, sum);
            }
        }

        // Create and save histogram visualization
        Mat imgHist = Mat::zeros(Size(MAX_HIST_SIZE, 100), CV_8UC1);
        for (int i = 0; i < MAX_HIST_SIZE && i < imgEdge.cols; i++) {
            int height = static_cast<int>((histogram[i] / static_cast<float>(max_val)) * 100);
            line(imgHist, Point(i, 100 - height), Point(i, 100), Scalar(255));
        }
        imwrite(hist_output, imgHist);
        cout << "Saved histogram to: " << hist_output << endl;

        // Find and crop threshold region
        int start_col = -1, end_col = -1;
        for (int i = 0; i < imgEdge.cols; i++) {
            if (histogram[i] >= 2500 && histogram[i] <= 6500) {
                if (start_col == -1) start_col = i;
                end_col = i;
            }
        }


        if (start_col != -1 && end_col != -1) {
            Mat cropped_edge(imgEdge, Rect(start_col, 0, end_col - start_col + 1, imgEdge.rows));
            string threshold_region_output = create_output_path(input_path, "_threshold_region.png");
            imwrite(threshold_region_output, cropped_edge);
            cout << "Saved threshold region to: " << threshold_region_output << endl;
            cout << "Threshold range: " << start_col << " to " << end_col << endl;

            // Display results
            //imshow("Original Image", frame);
            imshow("Cropped Region", crop);
            imshow("Polar Transform", polar_image);
            imshow("Edge Rotation", imgEdge);
            imshow("Histogram", imgHist);
            imshow("Threshold Region", cropped_edge);
            cout << "Histogram values:" << endl;
            for (int i = 0; i < imgEdge.cols; i++) {
                cout << "histogram[" << i << "] = " << histogram[i] << endl;
            }
        }
        else {
            cout << "No regions found within threshold range 4000-6000" << endl;
        }
    }
    else {
        cout << "No valid contours found in the image" << endl;
    }

    // Wait for key press and clean up
    waitKey(0);
    destroyAllWindows();
    return 0;
}

