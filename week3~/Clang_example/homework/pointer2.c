#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 6


int write_array(int score[], int index, int value) {
	score[index] = value;
	return 0;

}

int print_array(int* score) {
	float avg = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d : %d\n", i, *(score+i));
		avg += (float)*(score+i);
	}
	avg = avg / MAX_SIZE;
	printf("\nScore Avarage is %f\n\n", avg);
	return 0;
}

int pnp(int* score) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (*(score + i) < 60) {
			printf("%d is non-pass\n", i);
		}
		else {
			printf("%d is pass\n", i);
		}
	}
	return 0;
}


int main()
{
	int score[MAX_SIZE] = { 0, };
	int val;
	
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("input value : ");
		scanf("%d", &val);
		printf("\n");
		write_array(score, i, val);
	}

	print_array(score);
	pnp(score);


	return 0;
}