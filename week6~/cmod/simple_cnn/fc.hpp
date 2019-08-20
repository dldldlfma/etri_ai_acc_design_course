#include "common.hpp"

class Fc
{
    private:
        
    public:
        int input_size;
        int output_size;
        Mat2D weight;
        Mat1D bias;
        Fc(int input_size, int output_size);
        //~Fc();
        Mat1D forward(Mat1D in_mat, int activation=0);
        void init_weight();
        void weight_load(char* path);
		void bias_load(char* path);

};
