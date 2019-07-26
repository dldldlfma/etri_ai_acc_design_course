#include <stdio.h>

int main(){
    int arr[10]={0,};

    for(int i=0; i< (sizeof(arr) / sizeof(int)) ; i++ ){
        printf("%d, ", i);
    }
    return 0;
}