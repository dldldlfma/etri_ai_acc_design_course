#include <stdio.h>

struct Student{
    char name[50];
    double score[5];
    double average, total;
    char pass_fail;
};

int main(){
    struct Student student[2];
    for(int i=0; i< 2; i++){
        printf("%d 번째 이름 : ",i+1);
        scanf("%s",student[i].name);
        printf("수학 : ");
        scanf("%lf",&student[i].score[0]);
        printf("영어 : ");
        scanf("%lf",&student[i].score[1]);
    }

    for(int i =0; i<2; i++){
        printf("%d 번째 이름 : %s \n", i+1, student[i].name);
        printf("%d 번째 수학 : %lf \n", i+1, student[i].score[0]);
        printf("%d 번째 영어 : %lf \n", i+1, student[i].score[1]);
    }

    return 0;
}