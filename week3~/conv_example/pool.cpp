#include "common.hpp"

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
