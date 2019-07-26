#include <stdio.h>


#define SIZE 10

int main(){

    int array[SIZE]={95,47,28,62,99,77,20,98,36,59};
    int max;
    int num=0;
    int *p=array;

    max=p[0];

    for(int i=0; i<SIZE; i++){
        if( *(p+i) > max ){
            num=i;
            max=*(p+i);
        }
    }

    printf("max value position : %d\n",num);

    return 0;

}