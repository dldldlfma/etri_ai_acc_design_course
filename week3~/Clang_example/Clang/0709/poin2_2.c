#include <stdio.h>

int main() {
    int a[2][3] = {{1,2,3},{4,5,6}};

    printf("&a[0][0] : %x \n", &a[0][0]);
    printf("&a[0][1] : %x \n", &a[0][1]);

    printf("a[0]+1 : %x \n", a[0] +1);

    return 0;
}