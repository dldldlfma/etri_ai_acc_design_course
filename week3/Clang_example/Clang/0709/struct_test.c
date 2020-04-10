#include <stdio.h>

struct Test{
    int a,b,c,d;
};

int main(){
    struct Test test_st;
    struct Test *p_st;

    p_st = &test_st;
    (*p_st).a = 1;
    (*p_st).b = 2;

    printf("test_st의 a 멤버 : %d \n",test_st.a);
    printf("test_st의 b 멤버 : %d \n",test_st.b);
}