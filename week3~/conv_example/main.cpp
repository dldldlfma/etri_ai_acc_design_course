#include "common.hpp"
#include "conv.hpp"
#include "pool.hpp"
#include "activation.hpp"
#include <vector>

using namespace std;
using namespace cv;


typedef vector<cv::Mat> Mat3D;
typedef vector<Mat3D> Mat4D;


//func declation 
Mat3D input_init(Mat img);
	

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

	Mat bgr[3];

	
	for(int i=0; i<init_val.size(); i++){
		init_val[i].copyTo(bgr[i]);
		cout<<i<<" : "<< bgr[i].size()<<endl;
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
	Conv conv1(3,5,3);
	Conv conv2(5,10,5,2,1);

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

	Mat3D t_mat = conv1.forward(init_val);
	cout<<t_mat.size()<<endl;
	for(int i=0; i<t_mat.size(); i++){
		cout<<t_mat[i].size()<<endl;
	}

	Mat3D next_mat = conv2.forward(t_mat);
	cout<<next_mat.size()<<endl;
	for(int i=0; i<next_mat.size(); i++){
		cout<<next_mat[i].size()<<endl;
	}


    return 0;

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




