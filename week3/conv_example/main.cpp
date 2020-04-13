#include "common.hpp"
#include "conv.hpp"
#include "pool.hpp"
#include "activation.hpp"
#include "fc.hpp"
#include <vector>

using namespace std;
using namespace cv;

//------------------func declation-------------------------------
Mat3D input_init(Mat img);
void Mat_check(Mat3D A);
Mat1D view(Mat3D A);

int main(int argc, char* argv[])
{

    cout << "Hello OpenCV " << CV_VERSION << endl;

//------------------Init funciton test---------------------------

	Mat3D mnist_input_test;
	mnist_input_test.push_back(cv::Mat::zeros(28,28,CV_32F));

	FILE* file = fopen(argv[1],"r");
	double val=0;
	for(int i=0; i<28; i++){
		for(int j=0; j<28; j++){
			fscanf(file,"%lf\n",&val);
			mnist_input_test[0].at<float>(i,j) = (float)val;
		}
	}
	fclose(file);


//--------------layer define-----------------------------------
	Conv conv1(1,6,5);
	Pool pool1(2);
	Conv conv2(6,16,5);
	Pool pool2(2,1);
	Fc fc1(256, 84);
	Fc fc2(84, 10);

	//cout<<"conv1 load"<<endl;
	char* fp ="./pytorch/conv1_weight.txt";
	conv1.weight_load(fp);

	fp ="./pytorch/conv1_bias.txt";
	conv1.bias_load(fp);
	//cout<<endl;

	//cout<<"conv2 load"<<endl;
	fp ="./pytorch/conv2_weight.txt";
	conv2.weight_load(fp);

	fp ="./pytorch/conv2_bias.txt";
	conv2.bias_load(fp);
	//cout<<endl;

	//cout<<"fc1 load"<<endl;
	fp="./pytorch/fc1_weight.txt";
	fc1.weight_load(fp);

	//cout<<endl<<endl;
	//cout<<"fc2 load"<<endl;
	fp="./pytorch/fc2_weight.txt";
	fc2.weight_load(fp);


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

	cout<<"calc start"<<endl;

	Mat3D conv1_out = conv1.forward(mnist_input_test);
	//Mat_check(conv1_out);
	Mat3D pool1_out = pool1.forward(conv1_out);
	//Mat_check(pool1_out);
	Mat3D conv2_out = conv2.forward(pool1_out);
	//Mat_check(conv2_out);
	Mat3D pool2_out = pool2.forward(conv2_out);
	//Mat_check(pool2_out);
	Mat1D flatten_out = view(pool2_out);
	//cout<<flatten_out.size()<<endl;
	Mat1D fc1_out = fc1.forward(flatten_out,RELU);
	//cout<<fc1_out.size()<<endl;
	Mat1D fc2_out = fc2.forward(fc1_out);
	//cout<<fc2_out.size()<<endl;
	
	cout<<endl;
	float sum = 0;
	for(int i=0; i<fc2_out.size(); i++){
		//cout<<fc2_out[i]<<endl;
		sum += exp(fc2_out[i]);
	}
	//cout<<sum<<endl;
	//cout<<endl;

	//softmax
	cout<<"Test number : " <<argv[1]<<endl;
	for(int i=0; i<fc2_out.size(); i++){
		cout<<i<<" : "<<exp(fc2_out[i])/sum<<endl;
	}



	//cv::imshow("num",mnist_input_test[0]);
	//cv::waitKey(0);

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
