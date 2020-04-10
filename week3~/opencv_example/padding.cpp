#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double activation(double input){
    if(input >0){
        return input;
    }else{
        return 0;
    }
}

Mat img_padding(Mat image, int padding){
    int w = (int)(image.size().width+(2*padding));
    int h = (int)(image.size().height+(2*padding));
    cout<<"origin image size"<<endl;
    cout<<"width : "<<image.size().width<<" height : "<<image.size().height<<endl;
    cout<<"padding image size"<<endl;
    cout<<"width : "<<w<<" height : "<<h<<endl;

    Mat padding_img = Mat::zeros(h,w,CV_8UC3);
    
    for(int y=0; y<423; y++){
        for(int x=0; x<634; x++){
            //Vec3b pixel = image.at<cv::Vec3b>(y,x);
            padding_img.at<cv::Vec3b>(y+padding,x+padding) = image.at<cv::Vec3b>(y,x);
        }
    }

    return padding_img;
}


Mat Convolution(Mat A, Mat F, int padding, int stride){
    
    int o_col_size = (A.cols -F.cols )/stride +1; //already padding img
    int o_row_size = (A.rows -F.rows )/stride +1; //already padding img
    int i_col_size = (A.cols);
    int i_row_size = (A.rows);

    Mat out_img = Mat::zeros(o_row_size,o_col_size,CV_8UC1);


    uchar* A_d = A.data;
    char F_d[3][3];
    memcpy(F_d, F.data, 3*3*sizeof(char)); //F_d에 F의 data를 복사 

/*
    cout<<(int)F_d[0][0]<<endl;
    cout<<(int)F_d[0][1]<<endl;
    cout<<(int)F_d[0][2]<<endl;
    cout<<(int)F_d[1][1]<<endl;
*/

    uchar* O_d = out_img.data;

    cout<<"input  : "<<i_col_size<<"   "<<i_row_size<<endl;
    cout<<"output : "<<o_col_size<<"   "<<o_row_size<<endl;
        
    for(int o_row=0; o_row<o_row_size; o_row++){
        for(int o_col=0; o_col<o_col_size; o_col++){
            char out=0;
            for(int i=0; i<F.rows; i++){
                for(int j=0; j<F.cols; j++){
                     out+= A_d[(i+o_row * A.cols)+ j+o_col] * F_d[i][j];
                     //cout<<"out : "<<(int)out <<" / "<<(int)A_d[(i+o_row * A.cols)+ j+o_col]<<" " <<(int)F_d[i][j]<<endl;
                     }
            }
            out = activation(out);
            
            //cout<<o_row<<" " << o_col<<"save out : "<<(int)out<<endl;
            O_d[o_row * o_col_size + o_col] = out;
        }

    }
    return out_img;
}

int main()
{
    Mat image;
    
    image = imread("test.png",IMREAD_COLOR);
    if(image.empty()){
        cout <<"Could not opencv or find the image" <<endl;
        return -1;
    }
    

    char data[]={-1.0,-1.0,-1.0, -1.0,8.0,-1.0, -1.0,-1.0,-1.0};
    Mat filter(3,3,CV_8UC3,data);

/*
    int h=100;
    int w=100;
    
    Mat multi = Mat::zeros(h,w,(CV_8U,5));
    Mat multi_channel[5];
    split(multi,multi_channel);
    
    cout<<image.size()<<endl;
    for(int y=0; y<423; y++){
        for(int x=0; x<634; x++){
            Vec3b pixel = image.at<cv::Vec3b>(y,x);
            image.at<cv::Vec3b>(y,x)[2]=pixel.val[2]/2;
        }
    }
*/

    int padding=10;
    Mat padding_img = img_padding(image,padding);


    Mat bgr[3];
    split(padding_img, bgr);
    
    Mat out[3];
    Mat out[0] = Mat::zeros(652,441,CV_8UC1);
    Mat out[1] = Mat::zeros(652,441,CV_8UC1);
    Mat out[2] = Mat::zeros(652,441,CV_8UC1);
    

    out[0] = Convolution(bgr[0],filter,padding,1);
    out[1] = Convolution(bgr[1],filter,padding,1);
    out[2] = Convolution(bgr[2],filter,padding,1);

    Mat output(634,423,CV_8UC3);
    merge(out, padding_img);

/*
    uchar* image_data = image.data;
    uchar* padding_img_data = padding_img.data;


    int width=(int)image.size().width;
    for(int x=0; x<width; x++){
        uchar b = image_data[ x*3 ];
        uchar g = image_data[ x*3 + 1 ];
        uchar r = image_data[ x*3 + 2];

        cout<<"0"<<", "<<x<<" : "<<(int)b<<" "<<(int)g<<" "<<(int)r<<" "<<endl;
    }
    
    cout<<endl;
    width=(int)padding_img.cols;
    int height=(int)padding_img.rows;


    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
                uchar b = padding_img_data[y*width*3 + x*3 ];
                uchar g = padding_img_data[y*width*3 + x*3 + 1];
                uchar r = padding_img_data[y*width*3 + x*3 + 2];

                cout<<x<<" "<<y<<" : B "<<(int)b<<" G "<<(int)g<<" R "<<(int)r<<" "<<endl;
        }
    }
*/
    namedWindow("Original",WINDOW_AUTOSIZE);
    namedWindow("Padding_Img",WINDOW_AUTOSIZE);
    namedWindow("Padding_Img_conv",WINDOW_AUTOSIZE);
    
    imshow("Original", image);
    imshow("Padding_Img", bgr[0]);
    imshow("Padding_Img_conv", output);
    
    waitKey(0);
    return 0;
}