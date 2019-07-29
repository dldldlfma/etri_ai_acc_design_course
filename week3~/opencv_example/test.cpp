#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>

using namespace std;
using namespace cv;

#define RELU 0
#define SIGMOID 1

double activation(double a, int sel=RELU) {
    if(sel==RELU){
        return (a > 0) ? a : 0;
    }
    else if(sel==SIGMOID){
        return 1/(1+exp(-a));
    }
}

void activation_Mat(cv::Mat A){
    for(int i =0; i<A.size().height; i++){
        for(int j=0; j<A.size().width; j++){
            A.at<uchar>(i,j)=(uchar)activation((double)A.at<uchar>(i,j));
        }
    }
}


cv::Mat Padding2D(cv::Mat A, int padding) {
    cv::Mat A_padding = cv::Mat::zeros((int)A.size().height + (2 * padding),
        (int)A.size().width + (2 * padding),
        A.type());

    for (int i = 0; i < A.size().height; i++) {
        for (int j = 0; j < A.size().width; j++) {
            A_padding.at<uchar>(i + padding, j + padding) = A.at<uchar>(i, j);
        }
    }
    return A_padding;
}

cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride) {

    double out,result=0;
    int o_width, o_height;
    int f_width = F.size().width;
    int f_height = F.size().height;

    o_width = ((int)A.size().width - f_width + (2 * padding)) / stride + 1;
    o_height = ((int)A.size().height - f_height + (2 * padding)) / stride + 1;

    cv::Mat o_Mat = cv::Mat::zeros(o_height, o_width, CV_8UC1);
    cv::Mat pad_A;

    if (padding == 0) {
        printf("Non padding\n");
        pad_A = A;
    }

    else {
        pad_A = Padding2D(A, padding);
    }

    for (int h = 0; h < o_height; h++) {
        for (int w = 0; w < o_width; w++) {
            out = 0;
            for (int f_h = 0; f_h < f_height; f_h++) {
                for (int f_w = 0; f_w < f_width; f_w++) {
                    uchar a = pad_A.at<uchar>(((h * stride) + f_h), (w * stride + f_w));
                    double b = F.at<double>((f_h), (f_w));
                    result = (double)a*b;
                    out += result;
                }
            }
			if(out>255){
				out=255;
			}
            o_Mat.at<uchar>(h, w) = (uchar)activation(out);
        }
    }
    return o_Mat;
}

 

cv::Mat Max_Pool2D(cv::Mat A, int pool = 2) {

    uchar max;
    int o_width = ((int)A.size().width - pool) / pool + 1;
    int o_height = ((int)A.size().height - pool) / pool + 1;

    cv::Mat o_Mat = cv::Mat::zeros(o_height, o_width, CV_8UC1);
    for (int h = 0; h < o_height; h++) {
        for (int w = 0; w < o_width; w++) {
            max = 0;
            for (int i = 0; i < pool; i++) {
                for (int j = 0; j < pool; j++) {
                    if (max < A.at<uchar>((h * pool + i), (w * pool + j))) {
                        max = A.at<uchar>((h * pool + i), (w * pool + j));
                    }
                }
            }
            o_Mat.at<uchar>(h, w) = max;
        }
    }
    return o_Mat;
}

 

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
	split(result,bgr_result);
	for (int i = 0; i < result.size().height; i++) {
        for (int j = 0; j < result.size().width; j++) {
            cout<<(int)bgr_result[0].at<uchar>(i,j)<<" ";
        }
		cout<<endl;
    }

    //-------------------------Image Show---------------------------------//
    cv::imshow("image", img);
    cv::imshow("image_conv&padding", img_padding);
    cv::imshow("opencv_filter",test);

    //cv::imshow("single_channels", bgr[0]);
	cv::imshow("result",result);
    cv::imshow("single_channels_conv&padding_0", bgr_result[0]);
    cv::imshow("single_channels_conv&padding_1", bgr_result[1]);
    cv::imshow("single_channels_conv&padding_2", bgr_result[2]);
    //cv::imshow("pool", Pool);

    //------------------------Image Write--------------------------------//
    cv::imwrite("./paddding.jpg", img_padding);
    cv::imwrite("./filtering.jpg", padding_bgr[0]);
    cv::imwrite("./pool.jpg", Pool);

    cv::waitKey(0);
    return 0;

}
