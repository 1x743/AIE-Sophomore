#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <path_to_image>" << endl;
        return -1;
    }

    Mat src = imread(argv[1], IMREAD_COLOR);
    if (src.empty())
    {
        cout << "Error: Could not open or find the image." << endl;
        return -1;
    }

    Mat gray, dst;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, dst);

    imshow("Source Image", gray);
    imwrite("elena_gray.jpg", gray);
    imshow("Equalized Image", dst);
    imwrite("elena_gray_equalization.jpg", dst);

    waitKey(0);
    return 0;
}
