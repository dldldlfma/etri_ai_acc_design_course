#include "Neuron.h"

int main() {

	double learning_rate = 0.05;

	Neuron n1(2, learning_rate, SIGMOID);
	Neuron n2(2, learning_rate, SIGMOID);
	Neuron n3(2, learning_rate, SIGMOID);

	vector<vector<double> > inputX;
	vector<double> inputY;
	vector<double> temp;
	
	temp.push_back(0.0);
	temp.push_back(0.0);
	inputX.push_back(temp);
	temp[0] = (0.0);
	temp[1] = (1.0);
	inputX.push_back(temp);
	temp[0] = (1.0);
	temp[1] = (0.0);
	inputX.push_back(temp);
	temp[1] = (1.0);
	inputX.push_back(temp);
	
	
	inputY.push_back(0.0);
	inputY.push_back(1.0);
	inputY.push_back(1.0);
	inputY.push_back(0.0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cout << inputX[i][j]<< " ";
		}
		cout << inputY[i];
		cout <<endl;
	}
	
	double n1_out, n2_out, error, out;
	
	for(int epoch=0; epoch<500000000; epoch++){
		for (int i = 0; i < 4; i++) {
			n1_out=n1.feedforward(inputX[i]);
			n2_out=n2.feedforward(inputX[i]);
			temp[0] = n1_out;
			temp[1] = n2_out;
			out=n3.feedforward(temp);

			if (epoch % 1000000 == 0)
			{
				printf("%d => %lf %lf :  H : %lf \n", epoch, inputX[i][0], inputX[i][1], out);
			}
			error = inputY[i]-out;
			
			n3.backprop(error, temp);
			n2.backprop(n3.send_dw * n3.w[1], inputX[i]);
			n1.backprop(n3.send_dw * n3.w[0], inputX[i]);
		}

		if (epoch % 1000000 == 0)
		{
			printf("\n");
		}
	}
	cout << n3.w[0] << " " << n3.w[1] << endl;
	cout << n2.w[0] << " " << n2.w[1] << endl;
	cout << n1.w[0] << " " << n1.w[1] << endl;

	return 0;
}