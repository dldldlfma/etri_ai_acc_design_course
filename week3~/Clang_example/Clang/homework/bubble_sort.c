#include <stdio.h>

#define SIZE 10

void bubble_sort(int *A){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(A[j+1] < A[j]){
                swap(&A[j+1], &A[j]);
            }
        }
        print_arr(A);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void print_arr(int *A){
    for(int i=0; i<SIZE; i++){
        printf("%d, ",A[i]);
    }
    printf("\n");
}


int main(){
    int Number[SIZE] ={9,3,6,14,4,3,2,17,15,21};

    print_arr(Number);

    bubble_sort(&Number);

    print_arr(Number);
    

}