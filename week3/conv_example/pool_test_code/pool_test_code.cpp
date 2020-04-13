#include "../common.hpp"
#include "../pool.hpp"
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
	Pool pool1(2,1);
	
	Mat3D pool1_out = pool1.forward(mnist_input_test);
	Mat_check(pool1_out);

    Mat1D result = view(pool1_out);

    file = fopen("./pool_result.txt","w");

    for(int num=0; num<result.size(); num++){
        fprintf(file,"%f\n",result[num]);
    }
		
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
