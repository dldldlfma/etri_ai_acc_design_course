class Conv
{
	public:
		int in_channel;
		int out_channel;
        int f_size;
		int stride;
		int padding;
		Mat4D weight;
		Mat1D bias;

		void weight_init();
		Mat3D forward(Mat3D input_img);
		cv::Mat init_Mat();
		void weight_load(char* path);
		void bias_load(char* path);

		Conv(int in_c, int out_c, int f_size, int stride=1, int padding=0);

};

cv::Mat Padding2D(cv::Mat A, int padding);
cv::Mat Conv2D(cv::Mat A, cv::Mat F, int padding, int stride);
