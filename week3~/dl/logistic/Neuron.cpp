#include "Neuron.h"

int main()
{
    Neuron test(1.0, 0.0);
    test.randomGenerate();

    double cost;
   

    for(int i=0; i<100000000; i++)
    {
        if(i%1000==0){
            printf("Training %d \n",i);
            test.feedForwardAndPrint(0);
            test.feedForwardAndPrint(10);
            test.feedForwardAndPrint(20);
            test.feedForwardAndPrint(30);
            test.feedForwardAndPrint(49);
            test.feedForwardAndPrint(50);
            test.feedForwardAndPrint(60);
            test.feedForwardAndPrint(70);
            test.feedForwardAndPrint(80);
            test.feedForwardAndPrint(90);
            test.feedForwardAndPrint(100);
            printf("W = %f, b = %f \n\n", test.w, test.b);
        }
        
        test.backProp(test.X, test.Y);
        }

}