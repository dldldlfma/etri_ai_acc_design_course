class Pool
{
private:
        int pool_size;
        int type;
public:
    Pool(int pool_size=2, int type = 0);
    ~Pool();
    Mat3D forward(Mat3D input_img);
    cv::Mat Max_Pool2D(cv::Mat A, int pool = 2);
    cv::Mat Avg_Pool2D(cv::Mat A, int pool = 2);
    void info();
};
