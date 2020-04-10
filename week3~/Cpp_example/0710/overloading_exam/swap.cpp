#include <iostream>

using namespace std;

void swap(int* A, int* B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

void swap(char *A, char *B){
	char temp = *A;
	*A = *B;
	*B = temp;
}

void swap(double *A, double *B){
	double temp = *A;
	*A = *B;
	*B = temp;
}


int main(){
	int i_a=5, i_b=3;
	char c_a='a', c_b='b';
	double d_a=3.3, d_b=6.2;

	cout<<"int : "<<i_a<<"  "<<i_b<<endl;
	cout<<"char : "<<c_a<<"  "<<c_b<<endl;
	cout<<"double : "<<d_a<<"  "<<d_b<<endl;

	swap(&i_a, &i_b);
	swap(&c_a, &c_b);
	swap(&d_a, &d_b);

	cout<<"int : "<<i_a<<"  "<<i_b<<endl;
	cout<<"char : "<<c_a<<"  "<<c_b<<endl;
	cout<<"double : "<<d_a<<"  "<<d_b<<endl;


	return 0;

}


