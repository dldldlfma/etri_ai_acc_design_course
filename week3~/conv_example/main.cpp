#include "common.hpp"
#include "conv.hpp"
#include "pool.hpp"
#include "activation.hpp"
using namespace std;
using namespace cv;

int main()
{

    cout << "Hello OpenCV " << CV_VERSION << endl;
    clock_t begin, end;

    cv::Mat img;
    img = cv::imread("car.jpg");

    if (img.empty()) {
        cout << "Image load failed!" << endl;
        return -1;
    }

    int padding = 1;
    int stride = 1;
    cv::Mat img_padding;

    cv::Mat bgr[3];
    cv::Mat padding_bgr[3];

    cv::split(img, bgr);

    //----------------------------Filter Define-----------------------------------//
    double edge[] = {-1,-1,-1, -1,8,-1, -1,-1,-1};
    double edge5x5[] = { 0,0,-3,0,0,
                         0,0,0,0,0,
                         -3,0,12,0,-3,
                         0,0,0,0,0,
                         0,0,-3,0,0
                        };

 

    double blur[] = { 0.0625, 0.125, 0.0625,
    0.125, 0.25, 0.125,
    0.0625, 0.125, 0.0625 };

    double blur5x5[] = { 
        0.00390625, 0.015625, 0.0234375, 0.015625, 0.00390625,
        0.015625, 0.0625, 0.09375, 0.0625, 0.015625,
        0.0234375, 0.09375, 0.140625, 0.09375, 0.0234375,
        0.015625, 0.0625, 0.09375, 0.0625, 0.015625,
        0.00390625, 0.015625, 0.0234375, 0.015625, 0.00390625 };

    cv::Mat edge_filter(3, 3, CV_64F, edge);
    cv::Mat edge_5x5_filter(5, 5, CV_64F, edge5x5);
    cv::Mat blur_filter(3, 3, CV_64F, blur);
    cv::Mat blur5x5_filter(5, 5, CV_64F, blur5x5);

    //---------------------OpenCV filter2D----------------------------------//
    cv::Mat test;
    begin = clock();
    cv::filter2D(img,test,-1,edge_filter,cv::Point(-1,-1),(0.0),4);
    end = clock();
    printf("OpenCV conv time : %.3lf sec\n", (double)(end - begin)/CLOCKS_PER_SEC);


    
    //-----------------------Convolution-----------------------------------//
    for (int i = 0; i < sizeof(bgr) / sizeof(bgr[0]); i++) {
        begin = clock();
        padding_bgr[i] = Conv2D(bgr[i], edge_filter, padding, stride);
        end = clock();
        printf("conv time : %.3lf sec\n", (double)(end - begin)/CLOCKS_PER_SEC);

    }

    //-------------------------Pooling-------------------------------------//
    cv::Mat Pool;
    begin = clock();
    Pool = Max_Pool2D(padding_bgr[0], 2);
    end = clock();
    printf("Pooling time : %.3lf sec\n", (double)(end - begin)/CLOCKS_PER_SEC);
    
    //-------------------------Merge-------------------------------------//
    cv::merge(bgr, 3, img);
    cv::merge(padding_bgr, 3, img_padding);

	//-----------------------_TEST--------------------------------------//

	Mat bgr_result[3];
	Mat result = test-img_padding;

    //-------------------------Image Show---------------------------------//
    cv::imshow("image", img);
    cv::imshow("image_conv&padding", img_padding);
    cv::imshow("opencv_filter",test);

    //cv::imshow("single_channels", bgr[0]);
	cv::imshow("result",result);
    //cv::imshow("pool", Pool);

    //------------------------Image Write--------------------------------//
    cv::imwrite("./paddding.jpg", img_padding);
    cv::imwrite("./filtering.jpg", padding_bgr[0]);
    cv::imwrite("./pool.jpg", Pool);

    cv::waitKey(0);
    return 0;

}