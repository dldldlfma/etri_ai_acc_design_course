#include <iostream>
#include <cstdio>
#include "Neuron.h"

int main()
{
    Neuron single_neuron(1.0,3.0, LINEAR,0.1);

    double input[3] = {1,2,3};
    double output[3] = {1,2,3};
    double H;

    for(int num=0; num<2000; num++){
        cout<<"num : "<<num<<endl;
        for(int i=0; i<3; i++){
            H=single_neuron.feedForwardAndPrint(input[i]);
            single_neuron.backProp(output[i], H, input[i]);
            cout<<"W : "<<single_neuron.w<<" b : " <<single_neuron.b<<endl;
        }
        cout<<endl;
    }

    cout<<"input 2.5 result : "<<single_neuron.feedForward(2.5)<<endl;
    return 0;
}