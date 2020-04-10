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

        double sigma_val[3];

        double activation(const double sigma){
            double result;
            switch(this->sel_act){
                case SIGMOID: result = sigmoid(sigma); break;
                
                case RELU: result = (sigma>0) ? sigma:0;

                case LINEAR: result = sigma;
            }
            return result;
        }

        double feedForward(const double input, int num){
            const double sigma = (this->w) * input + (this->b);
            this->sigma_val[num]=sigma;
            return this->activation(sigma);
        }

        double feedForwardAndPrint(const double input, int num){
            double output = this->feedForward(input, num);
            cout<<"feedForward result : "<<output<<endl;
            return output;
        }

        void backProp(vector<double> inputX, vector<double> inputY){

			double dw=0;
			double db=0;
            double H;

			int n=static_cast<int>(inputX.size());

            double dE_dy;
            double dy_df=1;
            double df_dsigma;
            double dsigma_dw;

			for(int i =0; i<n;i++){
                dE_dy = (feedForward(inputX[i],i)-inputY[i]);

                switch(this->sel_act){
                    case SIGMOID: df_dsigma = sigmoid(this->sigma_val[i])*(1-sigmoid(this->sigma_val[i])) ; break;
                    case RELU: df_dsigma = ((this->sigma_val[i])>0) ? 1:0;
                    case LINEAR: df_dsigma = 1;
                }
                dsigma_dw = inputX[i];

                dw += dE_dy * dy_df * df_dsigma * dsigma_dw;
                db += dE_dy * dy_df * df_dsigma;
			}
            
            this->dw = dw/3;
            this->db = db/3;

            update();
        }

        void update(){
            w=w-lr*dw;
            b=b-lr*db;
            dw=0;
            db=0;
        }

		double getCost(double input, double output, int num){
			double cost = 0.5 * pow(output - feedForward(input, num) , 2);
		}

		double getTotalCost(vector<double> inputX, vector<double> inputY){
			int n = static_cast<int>(inputX.size());
			double cost=0;

			for(int i=0; i<n; i++){
				cost += (double)getCost(inputX[i], inputY[i], i);
                cout<<cost<<endl;
			}

			return cost/n;
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

