#include <stdio.h>

struct Test{
    int a,b;
};

int init_struct(struct Test *st, int a, int b){
    st->a=a;
    st->b=b;
    return 0;
}

int main(){
    struct Test st1;

    init_struct(&st1, 1,2);
    printf("st1의 a : %d, b : %d \n",st1.a, st1.b);
    return 0;
}