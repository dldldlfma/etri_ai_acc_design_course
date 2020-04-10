#include <stdio.h>

typedef struct Student{
    int math, science, social, avg;
    struct Student *NextStudent;
}Student;


void init_student(Student *A, int math, int science, int social){
    A->math=math;
    A->science=science;
    A->social=social;
    A->avg = (float)((math + science + social) /3);
}

Student* create(Student *A){
    Student* newStudent = (Student *)malloc(sizeof(Student));
    newStudent->math = A->math;
    newStudent->science = A->science;
    newStudent->social = A->social;
    newStudent->avg = A->avg;

    newStudent->NextStudent=NULL;

}

Student* create(Student *A){
    Student* newStudent = (Student *)malloc(sizeof(Student));
    newStudent->math = A->math;
    newStudent->science = A->science;
    newStudent->social = A->social;
    newStudent->avg = A->avg;

    newStudent->NextStudent=NULL;

}




int main(){
    int set;

    switch(set){
        case 0: break;
        case 1: break;
        case 2: break;
        case 3: break;
        default : break;
    }

}