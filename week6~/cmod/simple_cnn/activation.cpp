#include "common.hpp"

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
