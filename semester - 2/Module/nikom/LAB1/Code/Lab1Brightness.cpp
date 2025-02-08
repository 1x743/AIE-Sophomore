#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */

int main( int argc, char** argv )
{
	/// Read image given by user
	Mat image = imread( argv[1] );
	Mat new_image = Mat::zeros( image.size(), image.type() );

	/// Initialize values
	std::cout<<" Basic Linear Transforms "<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
	std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;

	/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	int max0, max1, max2, min0, min1, min2;
	max0 = min0 = image.at<Vec3b>(0, 0)[0];
	max1 = min1 = image.at<Vec3b>(0, 0)[1];
	max2 = min2 = image.at<Vec3b>(0, 0)[2];
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			if (image.at<Vec3b>(y, x)[0] > max0)
				max0 = image.at<Vec3b>(y, x)[0];
		}
	}

	for( int y = 0; y < image.rows; y++ )
	{ 
		for( int x = 0; x < image.cols; x++ )
		{ 
			for( int c = 0; c < 3; c++ )
			{
				new_image.at<Vec3b>(y,x)[c] =
				saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
			}
		}
	}

	/// Create Windows
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	/// Show stuff
	imshow("Original Image", image);
	imshow("New Image", new_image);
	imwrite("elena.jpg", new_image);

	/// Wait until user press some key
	waitKey(0);
	return 0;
}