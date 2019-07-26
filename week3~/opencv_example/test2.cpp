#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    
    image = imread("test.png",IMREAD_COLOR);
    if(image.empty()){
        cout <<"Could not opencv or find the image" <<endl;
        return -1;
    }

    Mat bgr[3];
    split(image, bgr);
    
    cout<<image.size()<<endl;
    for(int y=0; y<423; y++){
        for(int x=0; x<634; x++){
            Vec3b pixel = image.at<cv::Vec3b>(y,x);
            image.at<cv::Vec3b>(y,x)[2]=pixel.val[2]/2;
        }
    }
    
    namedWindow("Original",WINDOW_AUTOSIZE);
    namedWindow("R",WINDOW_AUTOSIZE);
    namedWindow("G",WINDOW_AUTOSIZE);
    namedWindow("B",WINDOW_AUTOSIZE);


    imshow("Original", image);
    imshow("R", bgr[2]);
    imshow("G", bgr[1]);
    imshow("B", bgr[0]);
    
    waitKey(0);
    return 0;
}