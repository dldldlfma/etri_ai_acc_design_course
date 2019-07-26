#include <stdio.h>
#include <math.h>

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
	int val, result;
	printf("input value :");
	scanf("%d", &val);

	result = square_num(val);

	if (result) {
		printf("%d is square_number\n", val);
	}
	else {
		printf("%d isn't square_number\n", val);
	}
	return 0;
}