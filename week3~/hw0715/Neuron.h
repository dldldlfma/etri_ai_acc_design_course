#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

#define RELU 0
#define SIGMOID 1
#define LINEAR 2

using namespace std;

class Neuron
{
public:
	vector<double> w;
	double b;
	vector<double> dw;
	double forword;
	double db;
	int act_sel;
	double send_dw;
	double lr;

	Neuron(int num_of_weight, double lr, int act_sel= SIGMOID) {
		
		for (int i = 0; i < num_of_weight; i++) {
			w.push_back(rand() / (double)RAND_MAX);
			dw.push_back(0.0);
		}
		this->b = (rand() / (double)RAND_MAX);
		cout << "Number of Weight : " << w.size() << endl;

		this->lr = lr;
		this->act_sel = act_sel;
		
	}

	~Neuron(){}

	double activation(double input) {
		double output=0;
		switch (this->act_sel) {
		case RELU:
			if (input > 0)
			{
				output = input;
			}
			else {
				output = 0;
			}
			break;
		case SIGMOID: output = 1 / (1 + exp(-input)); break;
		case LINEAR: output = input; break;
		}
		return output;
	}

	double feedforward(vector<double> input) {
		double output=0;

		for (int i = 0; i < w.size(); i++) {
			output += input[i] * w[i];
		}
		output += b;
		this->forword = activation(output);
		return this->forword;
	}


	void backprop(double f_dw, vector<double> input) {
		double dE_dy, dy_df, df_ds=0, ds_dw;
		
		dE_dy = f_dw;
		dy_df = 1;
		
		switch (this->act_sel) {
		case SIGMOID: df_ds = (forword) * (1 - forword); break;
		case RELU: df_ds = (this->forword) ? 1 : 0; break;
		case LINEAR: df_ds = 1; break;
		};

		send_dw = dE_dy * dy_df * df_ds;

		for (int i = 0; i < w.size(); i++) {
			ds_dw = input[i];
			this->dw[i]=(send_dw * ds_dw);
		}

		db = send_dw;

		weight_update();
	}

	void weight_update() {
		for (int i = 0; i < w.size(); i++) {
			this->w[i] = this->w[i] + this->lr * this->dw[i];
		}
		this->b += this->lr * this->db;
	}

	void mult_lr(double val){
		this->lr = this->lr * val;
	}
};