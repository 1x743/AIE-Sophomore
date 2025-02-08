#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat src4; Mat src4_gray;
int thresh4 = 100;
int max_thresh4 = 255;
RNG rng4(12345);

bool contour_features(vector<Point> ct)
{
	double area;
	area = contourArea(ct);

	RotatedRect rt;
	rt = fitEllipse(ct);

	Moments mu;
	mu = moments(ct);

	double hu[7];
	HuMoments(mu, hu);

	//printf("area=%lf, angle=%f, bounding box=[%d, %d, %d, %d], m00 m01 m10 = [%lf, %lf, %lf], xavg =%lf, yavg=%lf\n", area, rt.angle, rt.boundingRect().x, rt.boundingRect().y, rt.boundingRect().width, rt.boundingRect().height, mu.m00, mu.m01, mu.m10, mu.m10/mu.m00, mu.m01/mu.m00);
	for (int i = 0; i < 7; i++)
		printf("%lf ", hu[i]);
	printf("\n");
	if (hu[0] < 0.18) return true;
	return false;
}

int main(int argc, char** argv)
{
	Mat dst_image1;
	Mat src, src_gray, dst;
	Mat grad;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	int c;

	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	Mat frame;
	frame = imread(argv[1]); // Read the file

	if (!frame.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	GaussianBlur(frame, dst_image1, Size(5, 5), 0, 0);
	cvtColor(dst_image1, src_gray, COLOR_BGR2GRAY);
	/// Generate grad_x and grad_y
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	/// Gradient X
	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	/// Gradient Y
	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	/// Total Gradient (approximate)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	threshold(grad, dst, 30, 255, 1);

	Mat threshold_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	/// Find contours  
	findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point>> contours_poly(contours.size());
	vector<vector<Point>> contours_cycle;
	vector<Rect> boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());
	int rect_size = 0;
	Rect rect;
	int j = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[j], 1, true);
		if (contours_poly[j].size() > 5)
		{
			if (contour_features(contours_poly[j]))
			{
				contours_cycle.push_back(contours_poly[j]);
				boundRect[j] = boundingRect(Mat(contours_poly[j]));
				minEnclosingCircle(contours_poly[j], center[j], radius[j]);
				Scalar color = Scalar(rng4.uniform(0, 255), rng4.uniform(0, 255), rng4.uniform(0, 255));
			}
			j++;
		}
	}

	/// Draw polygonal contour + bonding rects + circles
	Mat drawing = Mat::zeros(dst.size(), CV_8UC3);
	int max = 0;
	int max_idx = 0;
	for (int i = 0; i < contours_cycle.size(); i++)
	{
		if (boundRect[i].width * boundRect[i].height > max)
		{
			max = boundRect[i].width * boundRect[i].height;
			max_idx = i;
		}
	}
	{
		Scalar color = Scalar(rng4.uniform(0, 255), rng4.uniform(0, 255), rng4.uniform(0, 255));
		drawContours(drawing, contours_cycle, max_idx, color, 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(drawing, boundRect[max_idx].tl(), boundRect[max_idx].br(), color, 2, 8, 0);

		// Draw rectangle on the original input image
		rectangle(frame, boundRect[max_idx].tl(), boundRect[max_idx].br(), Scalar(0, 255, 0), 2, 8, 0);
	}

	imshow("Output", frame);
	Mat crop;
	Mat cropped(frame, boundRect[max_idx]);
	cropped.copyTo(crop);
	/// Show in a window
	//imshow("Contours", drawing);
	//imshow("edge", dst);
	/*imshow("blur", dst_image1);*/
	imshow("Crop", crop);
	waitKey(0); // Wait for a keystroke in the window
	return 0;

}