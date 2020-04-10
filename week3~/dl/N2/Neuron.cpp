#include <iostream>
#include <cstdio>
#include "Neuron.h"

using namespace std;

int main()
{
	vector<double> X,Y;

	for(int i=0; i<3; i++){
		X.push_back(double(i) +1.0);
		Y.push_back(double(i) +1.0);
	}

	//init and data input
    Neuron single_neuron(1.0,3.0, LINEAR,0.01);
	single_neuron.assignData(X,Y);

	double cost;
	double target = 2.5;


    for(int num=0; num<10000; num++){
        cout<<"num : "<<num<<endl;
        cost = single_neuron.getTotalCost(X,Y);
        cout<<"cost : "<<cost<<endl;
        single_neuron.backProp(X,Y);
        
    }

    for(double i=0; i<10; i++){
        cout<<"input : "<<i <<"/ result : "<<single_neuron.feedForward(i,0)<<endl;
    }
        
    return 0;
}
