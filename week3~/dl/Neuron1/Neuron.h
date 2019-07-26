#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define SIGMOID 0
#define RELU 1
#define LINEAR 2


double sigmoid(double input)
{
    return (1/( 1+ exp(-input) ));
}

class Neuron
{
    public:
        double w;
        double b;
        vector<double> X;
        vector<double> Y;
        double dw;
        double db;
        int sel_act=LINEAR;
        double lr;

        double sigma_val;

        double activation(const double sigma){
            double result;
            switch(this->sel_act){
                case SIGMOID: result = sigmoid(sigma); break;
                
                case RELU: result = (sigma>0) ? sigma:0;

                case LINEAR: result = sigma;
            }
            return result;
        }

        double feedForward(const double input){
            const double sigma = (this->w) * input + (this->b);
            this->sigma_val = sigma;
            return this->activation(sigma);
        }

        double feedForwardAndPrint(const double input){
            double output = this->feedForward(input);
            cout<<"feedForward result : "<<output<<endl;
            return output;
        }

        void backProp(double target, double output, double input){
            printf("target : %f \n", target);

            double dE_dy = (output-target);
            double dy_df=1;
            double df_dsigma;
            switch(this->sel_act){
                case SIGMOID: df_dsigma = sigmoid(this->sigma_val)*(1-sigmoid(this->sigma_val)) ; break;
                case RELU: df_dsigma = (sigmoid(this->sigma_val)>0) ? 1:0;
                case LINEAR: df_dsigma = 1;
            } 

            double dsigma_dw = input;
            dw = dE_dy * dy_df * df_dsigma * dsigma_dw;
            db = dE_dy * dy_df * df_dsigma;

            update();
        }

        void update(){
            w=w-lr*dw;
            b=b-lr*db;
            dw=0;
            db=0;
        }



        void assignData(vector<double> inputX, vector<double> inputY){
            X.resize(inputX.size());
            Y.resize(inputY.size());
            copy(inputX.begin(),inputX.end(),X.begin());
            copy(inputY.begin(),inputY.end(),Y.begin());
        }

        Neuron()
        {
            this->w = 1;
            this->b = 3;
        }

        Neuron(double w_input, double b_input, int sel=LINEAR, double lr=0.01){
            this->w = w_input;
            this->b = b_input;
            this->sel_act=sel;
            this->lr=lr;
        }
};

