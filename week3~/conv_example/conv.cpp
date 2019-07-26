#include "common.hpp"

cv::Mat Padding2D(cv::Mat A, int padding);
cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride);


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
            else if(out<0){
                out=0;
            }
            o_Mat.at<uchar>(h, w) = (uchar)out;
        }
    }
    return o_Mat;
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