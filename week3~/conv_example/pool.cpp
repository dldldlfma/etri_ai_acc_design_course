#include "common.hpp"


class Pool
{
private:
        int pool_size;
public:
    Pool(int pool_size=2);
    ~Pool();
    Mat3D forward(Mat3D input_img);
    cv::Mat Max_Pool2D(cv::Mat A, int pool = 2);
};

Pool::Pool(int pool_size)
{
    this->pool_size=pool_size;
}

Pool::~Pool()
{
}

Mat3D Pool::forward(Mat3D in_mat){

    Mat3D output_mat;
    
    int o_width = ((int)in_mat[0].size().width - this->pool_size) / this->pool_size + 1;
    int o_height = ((int)in_mat[0].size().height - this->pool_size) / this->pool_size + 1;

    
    for(int o_c=0; o_c < in_mat.size(); o_c++){    
        cv::Mat pool_mat = cv::Mat::zeros(o_height, o_width, CV_32F);
        pool_mat = Max_Pool2D(in_mat[o_c],this->pool_size);
        output_mat.push_back(pool_mat);
    }
    return output_mat;
}

cv::Mat Pool::Max_Pool2D(cv::Mat A, int pool) {

    float max;
    int o_width = ((int)A.size().width - pool) / pool + 1;
    int o_height = ((int)A.size().height - pool) / pool + 1;

    cv::Mat o_Mat = cv::Mat::zeros(o_height, o_width, CV_32F);
    for (int h = 0; h < o_height; h++) {
        for (int w = 0; w < o_width; w++) {
            max = 0;
            for (int i = 0; i < pool; i++) {
                for (int j = 0; j < pool; j++) {
                    if (max < A.at<float>((h * pool + i), (w * pool + j))) {
                        max = A.at<float>((h * pool + i), (w * pool + j));
                    }
                }
            }
            o_Mat.at<float>(h, w) = max;
        }
    }
    return o_Mat;
}
