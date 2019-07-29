#include "common.hpp"
#include "conv.hpp"
#include "pool.hpp"
#include "activation.hpp"
#include "fc.hpp"
#include <vector>

using namespace std;
using namespace cv;



//func declation 
Mat3D input_init(Mat img);
void Mat_check(Mat3D A);
Mat1D view(Mat3D A);

int main()
{

    cout << "Hello OpenCV " << CV_VERSION << endl;
	cv::Mat img;
	img = cv::imread("car.jpg");

	if(img.empty()){
		cout<< "Image load failed!"<<endl;
		return -1;
	}

//------------------Init funciton test---------------------------

	Mat3D init_val = input_init(img);
	//cout<<"init_val.channel :"<<init_val.size()<<endl;

	Mat3D mnist_input_test;
	mnist_input_test.push_back(cv::Mat::zeros(28,28,CV_32F));

	Mat bgr[3];

	
	for(int i=0; i<init_val.size(); i++){
		init_val[i].copyTo(bgr[i]);
		//cout<<i<<" : "<< bgr[i].size()<<endl;
	}
	Mat merge_mat;

	cv::merge(bgr, 3, merge_mat);
	//cout<<merge_mat.channels()<<endl;
	


	img.convertTo(img, CV_32F);
	img = (img -0.5)/255;


	//imshow("origin", img);
	//imshow("after", merge_mat);
	//waitKey(0);

//--------------layer define-----------------------------------
	Conv conv1(1,6,5);
	Pool pool1(2);
	Conv conv2(6,16,5);
	Pool pool2(2);
	Fc fc1(256, 84);
	Fc fc2(84, 10);

	//------------- layer check-------------------------
	/*
	cout<<conv1.weight.size()<<endl;
	for(int i=0; i<conv1.weight.size(); i++){
		cout<<i<<" : "<<conv1.weight[i].size()<<endl;
		for(int j=0; j<conv1.weight[i].size(); j++){
			cout<<conv1.weight[i][j].size()<<endl;
		}
	}
	cout<<endl;
	*/

	Mat3D conv1_out = conv1.forward(mnist_input_test);
	Mat_check(conv1_out);

	Mat3D pool1_out = pool1.forward(conv1_out);
	Mat_check(pool1_out);

	Mat3D conv2_out = conv2.forward(pool1_out);
	Mat_check(conv2_out);

	Mat3D pool2_out = pool2.forward(conv2_out);
	Mat_check(pool2_out);

	Mat1D flatten_out = view(pool2_out);
	cout<<flatten_out.size()<<endl;

	Mat1D fc1_out = fc1.forward(flatten_out);
	cout<<fc1_out.size()<<endl;

	Mat1D fc2_out = fc2.forward(fc1_out);
	cout<<fc2_out.size()<<endl;


    return 0;

}

Mat1D view(Mat3D A){
	Mat1D out;
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A[0].size().height; j++){
			for(int k=0; k<A[0].size().width; k++){
				out.push_back(A[i].at<float>(j,k));
			}
		}
	}
	return out;
}

Mat3D input_init(Mat img){
	img.convertTo(img,CV_32F);
	img = (img -0.5) / 255;

	Mat input_img[3];
	cv::split(img, input_img);
	Mat3D out;
	//cout<<img.channels()<<endl;

	//img.channels will return Matrix channels
	if(img.channels()>1){
		for(int i=0; i<img.channels(); i++){
			out.push_back(input_img[i]);
		}
	}


	//cout<<out.size()<<endl;
	return out;
}

void Mat_check(Mat3D A){
	cout<<A.size()<<" x "<<A[0].size()<<endl;
}
