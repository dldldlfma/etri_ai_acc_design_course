#include <stdio.h>

int main(){
    double a[6] = {100, 87, 93};
    score_box(a);

    printf("총점 : %.2f, 평균 : %.2f \n", a[3], a[4]);
    return 0;

}

int score_box(double *a){
    double sum=0;
    for(int i =0; i<3; i++){
        sum+=*(a+i);
    }

    a[3]=sum;
    a[4]=sum/3;
    return 0;
}