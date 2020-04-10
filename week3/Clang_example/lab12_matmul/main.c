#include <stdio.h>

#define MAT_SIZE 4

int matsum(int A[][MAT_SIZE], int B[][MAT_SIZE], int size, int C[][MAT_SIZE])
{
	int i,j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	return 0;
}


void matprint(int mat[][MAT_SIZE], int size){
	int i,j;
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%d, ",mat[i][j]);
		}
		printf("\n");
	}
}

int matmult(int A[][MAT_SIZE], int B[][MAT_SIZE], int size, int C[][MAT_SIZE])
{
	int i,j,k;

	int sum;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			for(k=0; k<size; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return 0;
}


int main()
{
	int A[4][4]={
				 {1,0,0,0},
				 {0,1,0,0},
				 {0,0,1,0},
				 {0,0,0,1},
				};
	int B[4][4]={
				 {1,1,1,1},
				 {1,1,1,1},
				 {2,2,2,2},
				 {2,2,2,2},
				};
	int C[4][4]={
				 {0,},
				 {0,},
				 {0,},
				 {0,},
				};
	int C2[4][4]={
				 {0,},
				 {0,},
				 {0,},
				 {0,},
				};


	matsum(A,B,4,C);
	matprint(C,4);

	printf("\n\n ---- matmult---\n\n");
	matmult(A,B,4,C2);
	matprint(C2,4);


	return 0;

}


