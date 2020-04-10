#include <stdio.h>

int main(){
	int a[4]={1,2,3,4};
	int *p =a;
	int sum = 0;

	while(p-a <=3){
		sum += *p;
		p++;
	}

	printf("sum: %d \n", sum);

	return 0;
}
