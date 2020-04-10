#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
    uchar A_data[] = {1,2,3,
                      1,2,3,
                      1,2,3};
    Mat A = Mat(3,3,CV_8UC1,A_data);

    uchar B_data[] = {1,2,3,
                      1,2,3,
                      1,2,3};
    Mat B = Mat(3,3,CV_8UC1,B_data);

    Mat C = A+B;

    for(int i =0; i<C.size().height; i++){
        for(int j=0; j<C.size().width; j++){
            cout<<(short)C.at<uchar>(i,j)<<" ";
        }
        cout<<endl;
    }
}