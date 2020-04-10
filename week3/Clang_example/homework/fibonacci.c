#include <stdio.h>
#include <math.h>

void fibonacci(int num) {
	int i, last, now, temp;
	last = 0;
	now = 1;

	for (i = 0; i < num; i++) {
		printf("%d, ", now);
		temp = now;
		now = now + last;
		last = temp;		
	}


}


int main()
{
	int val;
	printf("input value : ");
	scanf("%d", &val);
	printf("\n");

	fibonacci(val);

	return 0;
}