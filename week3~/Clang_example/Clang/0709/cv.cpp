#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("./test.jpg",IMREAD_COLOR);
    if(image.empty())
    {
        cout << "Could net open or find the image" <<endl;
        return -1;
    }
    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", image);

    waitKey(0);
}