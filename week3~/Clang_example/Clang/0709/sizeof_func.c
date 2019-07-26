#include <stdio.h>

int main(){
    int a[2][3]={{1,2,3},{4,5,6}};

    printf("a의 바이트 : %d \n", sizeof(a));
    printf("a의 크기 : %d \n", sizeof(a)/sizeof(int) );

    return 0;
}