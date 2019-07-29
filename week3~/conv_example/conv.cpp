#include "common.hpp"

using namespace cv;
using namespace std;


cv::Mat Padding2D(cv::Mat A, int padding);
cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride, int o_h, int o_w);

class Conv
{
	public:
		int in_channel;
		int out_channel;
        int f_size;
		int stride;
		int padding;
		Mat4D weight;

		void weight_init();
		Mat3D forward(Mat3D input_img);
		cv::Mat init_Mat();

		Conv(int in_c, int out_c, int f_size, int stride=1, int padding=0);


};

Conv::Conv(int in_c, int out_c, int f_size, int stride, int padding){
			this->in_channel=in_c;
			this->out_channel=out_c;
			this->f_size=f_size;
			this->stride = stride;
			this->padding = padding;
			//cout<<"init start"<<endl;
			this->weight_init();
			//cout<<"init end"<<endl;
}

void Conv::weight_init(){
	this->weight = Mat4D(this->out_channel);
	//cout<<weight.size()<<endl;
	for(int i=0; i< this->out_channel; i++){
		this->weight[i] = Mat3D(this->in_channel);
		for(int j=0; j<this->in_channel; j++){
			this->weight[i][j].push_back(this->init_Mat());
		}
	}
}


Mat3D Conv::forward(Mat3D in_mat){
	Mat3D output_mat;

	int o_width = ((int)in_mat[0].size().width - this->f_size + (2*this->padding))/this->stride + 1;
	int o_height = ((int)in_mat[0].size().height - this->f_size + (2*this->padding)) / this->stride + 1;

	for(int o_c=0; o_c<this->out_channel; o_c++){
		cv::Mat sum_mat = cv::Mat::zeros(o_height, o_width, CV_32F);
		for(int i_c=0; i_c<this->in_channel; i_c++){
			sum_mat += Conv2D(in_mat[i_c], this->weight[o_c][i_c], this->padding, this->stride, o_height, o_width);
		}
		output_mat.push_back(sum_mat);
	}
	return output_mat;
}


cv::Mat Conv::init_Mat(){
	int f_s = this->f_size;
	cv::Mat A(f_s,f_s, CV_32F);
	for(int i=0; i<f_s; i++){
		for(int j=0; j<f_s; j++){
			A.at<float>(i,j) = ((float)(rand() / (float(RAND_MAX))) -0.5) ;
		}
	}
	return A;
}	


cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride, int o_h, int o_w) {

    double out,result=0;
    
	int o_width=o_w;
	int	o_height=o_h;

    int f_width = F.size().width;
    int f_height = F.size().height;


    cv::Mat o_Mat = cv::Mat::zeros(o_height, o_width, CV_32F);
    cv::Mat pad_A;

    if (padding == 0) {
		//printf("Non padding\n");
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
                    float a = pad_A.at<float>(((h * stride) + f_h), (w * stride + f_w));
                    float b = F.at<float>((f_h), (f_w));
                    result = (float)a*b;
                    out += result;
                }
            }
			if(out>255){
				out=255;
			}
            else if(out<0){
                out=0;
            }
            o_Mat.at<float>(h, w) = (float)out;
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
            A_padding.at<float>(i + padding, j + padding) = A.at<float>(i, j);
        }
    }
    return A_padding;
}


