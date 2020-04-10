#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

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

        double forward_out;

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
            forward_out = this->activation(sigma);
            return forward_out;
        }

        double feedForwardAndPrint(const double input){
            double output = this->feedForward(input);
            cout<<input<<" result : "<<output<<endl;
            return output;
        }

        void randomGenerate()
        {
            for(int i=0; i<100; i++)
            {
                this->X.push_back(rand()%50);
                this->Y.push_back(0);
            }

            for(int i=0; i<100; i++)
            {
                this->X.push_back(rand()%51 + 50);
                this->Y.push_back(1);
            }
        }

        void backProp(vector<double> inputX, vector<double> inputY){
            double dw=0;
            double db=0;
            double H;

            int n = static_cast<int>(inputX.size());

            double dE_dy;
            double dy_df=1;
            double df_dsigma;
            double dsigma_dw;

            for(int i= 0; i<n; i++){
                dE_dy = (feedForward(inputX[i]) - inputY[i]);

                switch(this->sel_act){
                    case SIGMOID: df_dsigma = (this->forward_out)*(1-this->forward_out); break;
                    case RELU: df_dsigma = ((this->forward_out)>0) ? 1:0; break;
                    case LINEAR: df_dsigma = 1; break;
                }
                dsigma_dw = inputX[i];

                dw += dE_dy * dy_df * df_dsigma * dsigma_dw;
                db += dE_dy * dy_df * df_dsigma;

            }
            this-> dw = dw/n;
            this-> db = db/n;
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

        Neuron(double w_input, double b_input, int sel=SIGMOID, double lr=0.01){
            this->w = w_input;
            this->b = b_input;
            this->sel_act=sel;
            this->lr=lr;
        }
};