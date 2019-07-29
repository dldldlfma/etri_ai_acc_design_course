class Conv
{
	public:
		int in_channel;
		int out_channel;
        int f_size=3;
		int stride=1;
		int padding=0;
		Mat4D weight;

		void weight_init();
		Mat3D forward(Mat3D input_img);

		Conv(int in_c, int out_c, int f_size, int stride=1, int padding=0);

};

cv::Mat Padding2D(cv::Mat A, int padding);
cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride);
