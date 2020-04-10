#include <stdio.h>

#define SIZE 10


int print_arr(int* arr){
    for(int i=0; i<SIZE; i++){
        printf("%d ,", *(arr+i));
    }
}

int main(){
    int arr[SIZE] = {1,};

    for(int i=0; i<SIZE; i++){
        *(arr+i) = *(arr + (i - 1)) + (i+1);
        printf("%d : %d, %d\n",i,(*arr+i), *(arr+i-1));
    }

    print_arr(arr);

    return 0;

    
}