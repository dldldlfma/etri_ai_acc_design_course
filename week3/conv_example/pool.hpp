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
