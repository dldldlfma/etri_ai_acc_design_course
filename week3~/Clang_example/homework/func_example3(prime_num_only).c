#include <stdio.h>


int primenum(int val) {
	int i, prime;
	prime = 1;
	for (i = 2; i < val; i++) {
		if (val % i == 0) {
			prime = 0;
			break;
		}
	}
	return prime;
}


int main()
{
	int val, prime;
	printf("input value : ");
	scanf("%d",&val);
	printf("\n");

	prime = primenum(val);

	if (prime == 1) {
		printf("%d is prime number\n", val);
	}
	else {
		printf("%d isn't prime number\n", val);
	}
	
	return 0;
}