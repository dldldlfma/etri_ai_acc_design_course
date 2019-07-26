#include <stdio.h>

int main(){
	int *p, a, b;

	
	p=&a;
	*p=2;
	p=&b;
	*p=4;


	printf("%x,\n",a);
	printf("%x\n",b);
	return 0;
}

