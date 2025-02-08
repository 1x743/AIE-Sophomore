#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int threshold_value = 0;
int threshold_type = 3;
const int max_value = 255;
const int max_type = 4;
const int max_BINARY_value = 255;

Mat src, src_gray, dst;
const char* window_name = "Threshold Demo";

const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";

/// Function headers
void Threshold_Demo(int, void*);

/**
 * @function main
 */
int main(int argc, char** argv) {
    /// Check for valid input
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return -1;
    }

    /// Load an image
    src = imread(argv[1], IMREAD_COLOR);
    if (src.empty()) {
        cout << "Error: Cannot load image!" << endl;
        return -1;
    }

    /// Convert the image to Gray
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    /// Create a window to display results
    namedWindow(window_name, WINDOW_AUTOSIZE);

    /// Create Trackbar to choose type of Threshold
    createTrackbar(trackbar_type, window_name, &threshold_type, max_type, Threshold_Demo);
    createTrackbar(trackbar_value, window_name, &threshold_value, max_value, Threshold_Demo);

    /// Call the function to initialize
    Threshold_Demo(0, 0);

    /// Wait until user finishes program
    while (true) {
        char c = (char)waitKey(20);
        if (c == 27) // ESC key
            break;
    }

    return 0;
}

/**
 * @function Threshold_Demo
 */
void Threshold_Demo(int, void*) {
    /* 0: Binary
       1: Binary Inverted
       2: Threshold Truncated
       3: Threshold to Zero
       4: Threshold to Zero Inverted
    */

    threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
    imshow(window_name, dst);
}
