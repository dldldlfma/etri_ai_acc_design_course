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
	cout<<"init_val.channel :"<<init_val.size()<<endl;

	Mat bgr[3];
	
	for(int i=0; i<init_val.size(); i++){
		init_val[i].copyTo(bgr[i]);
		cout<<i<<" : "<< bgr[i].size()<<endl;
	}
	Mat merge_mat;

	cv::merge(bgr, 3, merge_mat);
	cout<<merge_mat.channels()<<endl;



	img.convertTo(img, CV_32F);
	img = (img -0.5)/255;


	//imshow("origin", img);
	//imshow("after", merge_mat);
	//waitKey(0);

//-------------------------------------------------
	Conv conv1(3,64,3,1,1);
	cout<<conv1.weight.size()<<endl;


    return 0;

}


Mat3D input_init(Mat img){

	img.convertTo(img,CV_32F);
	img = (img -0.5) / 255;

	Mat input_img[3];
	cv::split(img,input_img);
	Mat3D out;

	//img.channels will return Matrix channels
	if(img.channels()>1){
		cv::split(img,input_img);

		for(int i=0; i<img.channels(); i++){
			out.push_back(input_img[i]);
		}
	}


	return out;
}
















