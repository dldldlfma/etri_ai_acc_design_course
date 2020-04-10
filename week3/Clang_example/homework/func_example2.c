#include <stdio.h>
#include <math.h>

void odd(int val) {
	if (val % 2 == 0) {
		printf("even number\n");
	}
	else {
		printf("odd number\n");
	}
}

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

void small_prime(int val) {
	int i = val - 1;
	while (i != 0) {
		if (primenum(i) == 1) {
			printf("%d is small prime number\n", i);
			break;
		}
		i--;
	}

}

int square_num(int val) {

	int temp = 0;

	switch (val & 0x0f) {
	case 0:
	case 1:
	case 4:
	case 9:
		temp = (unsigned int)(sqrt((double)val) + 0.5);
		return (temp * temp == val);

	default:
		return 0;

	}
}



int main()
{
	int val, prime, square;
	printf("input value : ");
	scanf("%d", &val);
	printf("\n");

	odd(val);
	prime = primenum(val);

	if (prime == 1) {
		printf("%d is prime number\n", val);
	}
	else {
		printf("%d isn't prime number\n", val);
	}

	small_prime(val);

	square = square_num(val);

	if (square == 1) {
		printf("%d is square number\n", val);
	}
	else {
		printf("%d isn't square number\n", val);
	}



	return 0;
}