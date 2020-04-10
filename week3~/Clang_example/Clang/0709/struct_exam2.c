#include <stdio.h>
#include <string.h>


struct Student{
    char name[50];
    double score[5];
    double average, total;
    char pass_fail;
};

int main(){
    struct Student student[2];

    student[1].score[0]=100;
    student[1].score[1]=90;

    strcpy(student[1].name , "홍길동");

    printf("%s\n", student[1].name);
    

    return 0;
}