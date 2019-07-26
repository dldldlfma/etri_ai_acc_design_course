#include <stdio.h>

#define SIZE 10

int* max_val(int *arr){
    int max=*(arr);

    for(int i=0; i< SIZE; i++){
        
        if(max<*(arr+i)){
            max=*(arr+i);
        }
    }

    return max;
}

int main(){
    int score[SIZE]= {1,3,5,2,6, 8,7,9,10,2};

    int max_value;

    max_value = max_val(score);

    printf("max value is %d\n", max_value);
    return 0;
}