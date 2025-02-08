#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
using namespace cv;
using namespace std;
using namespace cv::ml;


Mat gen_feature_input(Mat& image)
{
    float max = 0;
    int val[120];

    //Mat greyMat;
    //cvtColor(image, greyMat, COLOR_BGR2GRAY);

    for (int i = 0; i < image.cols; i++)
    {
        int column_sum = 0;
        for (int k = 0; k < image.rows; k++)
        {
            column_sum += image.at<unsigned char>(k, i);
        }
        val[i] = column_sum;
        if (val[i] > max) max = (float)val[i];
    }

    Mat data(1, image.cols, CV_32F);
    for (int i = 0; i < image.cols; i++)
    {
        data.at<float>(0, i) = static_cast<float>(val[i]) / static_cast<float>(max);

    }
    return data;
}
bool ann_classifier(const string& modelPath, Mat data)
{
    Ptr<ANN_MLP> model = ANN_MLP::load(modelPath);
    if (model.empty())
    {
        cerr << "Failed to load model: " << modelPath << endl;
        return false;
    }

    Mat result;
    model->predict(data, result);
    float r = result.at<float>(0, 0);
    cout << "Prediction result: " << r << endl;

    //return true;
    return (r >= 0.35) ? 1 : 0;
}

bool contour_features(vector<Point> contour) {
    double area = contourArea(contour);
    if (area < 100) return false;

    double perimeter = arcLength(contour, true);
    double circularity = 4 * CV_PI * area / (perimeter * perimeter);

    return circularity > 0.6;
}

void processImage(const char* imagePath) {
    Mat frame = imread(imagePath);
    if (frame.empty()) {
        cout << "Error: Could not read the image: " << imagePath << endl;
        return;
    }
    Mat imgOriginal = frame.clone();
    // Rotate image before processing
    Point2f center(static_cast<float>(frame.cols) / 2.0f, static_cast<float>(frame.rows) / 2.0f);
    float angle = 40.0f;
    float scaleFactor = 1.0f;

    Mat rotation_matrix = getRotationMatrix2D(center, angle, scaleFactor);
    Mat rotated_frame;
    warpAffine(frame, rotated_frame, rotation_matrix, frame.size());
    frame = rotated_frame;

    // Preprocessing
    Mat dst_image1, src_gray, dst, grad;
    GaussianBlur(frame, dst_image1, Size(5, 5), 0, 0);
    cvtColor(dst_image1, src_gray, COLOR_BGR2GRAY);

    // Compute gradients
    Mat grad_x, grad_y, abs_grad_x, abs_grad_y;
    Sobel(src_gray, grad_x, CV_16S, 1, 0, 3);
    Sobel(src_gray, grad_y, CV_16S, 0, 1, 3);
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);

    // Combine gradients and threshold
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    threshold(grad, dst, 5, 255, THRESH_BINARY);

    // Find contours
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    Mat contourImg = frame.clone();
    // Process contours
    vector<vector<Point>> contours_poly(contours.size());
    vector<Rect> boundRect;
    for (size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(contours[i], contours_poly[i], 1, true);
        if (contours_poly[i].size() > 5 && contour_features(contours_poly[i])) {
            boundRect.push_back(boundingRect(contours_poly[i]));
        }
    }

    // Find largest contour
    Rect largestRect;
    double maxArea = 0;
    for (const auto& rect : boundRect) {
        double area = rect.area();
        if (area > maxArea) {
            maxArea = area;
            largestRect = rect;
        }
    }

    if (maxArea == 0) {
        cout << "No significant contour found." << endl;
        return;
    }

    // Crop region of interest
    Mat imgCycle = frame(largestRect);

    // Polar transformation
    Point2f ct(imgCycle.cols / 2.0f, imgCycle.rows / 2.0f);
    Mat imgPolar;
    linearPolar(imgCycle, imgPolar, ct, max(imgCycle.cols, imgCycle.rows) / 2, WARP_FILL_OUTLIERS);

    // Extract and rotate edge region
    Mat imgEdge;
    Mat croppedEdgeRef(imgPolar, Rect(imgPolar.cols - 90, 0, 90, imgPolar.rows));
    croppedEdgeRef.copyTo(imgEdge);
    rotate(imgEdge, imgEdge, ROTATE_90_COUNTERCLOCKWISE);
    cvtColor(imgEdge, imgEdge, COLOR_BGR2GRAY);

    // Histogram analysis
    vector<int> histogram(1000, 0);
    int max_val = 0;
    for (int i = 0; i < imgEdge.cols; i++) {
        int sum = 0;
        for (int j = 0; j < imgEdge.rows; j++) {
            sum += imgEdge.at<uchar>(j, i);
        }
        histogram[i] = sum;
        max_val = max(max_val, sum);
    }

    // Locate bounding box from histogram
    int start_col = -1, end_col = -1;
    for (int i = 0; i < imgEdge.cols; i++) {
        if (histogram[i] >= 2500 && histogram[i] <= 6500) {
            if (start_col == -1) start_col = i;
            end_col = i;
        }
    }

    // Extract and process crack region
    if (start_col != -1 && end_col != -1) {
        Rect rectCrack(start_col, 0, end_col - start_col, imgEdge.rows);
        Mat imgCrack = imgEdge(rectCrack);
        resize(imgCrack, imgCrack, Size(120, 40));
        equalizeHist(imgCrack, imgCrack);
        float confidence = 0.0f;
        // Feature extraction and classification
        Mat feature = gen_feature_input(imgCrack);
        int prediction = ann_classifier("model.xml", feature);
        /*cout << "Final Prediction: " << (prediction ? "Crack" : "No Crack") << endl;
        cout << "Histogram values:" << endl;
        for (int i = 0; i < imgEdge.cols; i++) {
            cout << "histogram[" << i << "] = " << histogram[i] << endl;
        }*/
        Mat imgApp = Mat::zeros(Size(1024, 724), frame.type());
        // Place original image on left half
        Mat imgResized;
        resize(imgOriginal, imgResized, Size(512, 724));
        imgResized.copyTo(imgApp(Rect(0, 0, imgResized.cols, imgResized.rows)));

        resize(imgCrack, imgCrack, Size(256, 181));  // Resize imgCrack to desired size
        cvtColor(imgCrack, imgCrack, COLOR_GRAY2BGR);  // Convert to color image if it's grayscale
        imgCrack.copyTo(imgApp(Rect(768, 0, imgCrack.cols, imgCrack.rows)));
        resize(imgPolar, imgPolar, Size(256, 181));  // Resize linearPolar image to desired size
        imgPolar.copyTo(imgApp(Rect(768, 181, imgPolar.cols, imgPolar.rows)));
        // Display "Crack" text on top-right
        // Display "Crack" text on top-right
        resize(imgEdge, imgEdge, Size(256, 181));  // Resize imgEdge
        cvtColor(imgEdge, imgEdge, COLOR_GRAY2BGR);  // Convert to color image
        imgEdge.copyTo(imgApp(Rect(768, 362, imgEdge.cols, imgEdge.rows)));
        string resultText = prediction ? "Crack" : "No Crack";
        Mat imgHist = Mat::zeros(Size(1000, 100), CV_8UC1);  // Create a black image for the histogram

        // Find the maximum histogram value
        int max_val = 0;
        for (int i = 0; i < imgEdge.cols; i++) {
            max_val = max(max_val, histogram[i]);
        }

        // Draw the histogram
        for (int i = 0; i < 1000 && i < imgEdge.cols; i++) {
            // Normalize the histogram value to fit within the height of the imgHist
            int height = static_cast<int>((histogram[i] / static_cast<float>(max_val)) * imgHist.rows);
            line(imgHist, Point(i, imgHist.rows - height), Point(i, imgHist.rows), Scalar(255));
        }

        // Convert imgHist to 3 channels to match imgApp's number of channels
        Mat imgHistColor;
        cvtColor(imgHist, imgHistColor, COLOR_GRAY2BGR);  // Convert single-channel histogram to 3 channels (BGR)

        resize(imgHistColor, imgHistColor, Size(256, 181)); // Resize histogram image
        imgHistColor.copyTo(imgApp(Rect(768, 462, imgHistColor.cols, imgHistColor.rows)));  // Copy to the final image
        Scalar textColor = prediction ? Scalar(0, 0, 255) : Scalar(0, 255, 0); // Red for "Crack", Green for "No Crack"

        putText(imgApp, resultText, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, textColor, 3);


        std::filesystem::path p(imagePath);
        std::string filename = p.filename().string();  // Get the filename with extension

        // Prepare to display the filename on the bottom left corner of imgApp
        string inputText = "Input Image: " + filename;
        putText(imgApp, inputText, Point(10, imgApp.rows - 10), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        imshow("096-049", imgApp);
        waitKey();
    }
    else {
        cout << "No crack detected in the selected region." << endl;
    }
}


int main(int argc, char** argv)
{

    processImage(argv[1]);

    return 0;
}