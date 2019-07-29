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
        Mat1D forward(Mat1D in_mat);
        void init_weight();
        void weight_set(FILE* fp);

};