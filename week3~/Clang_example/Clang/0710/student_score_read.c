#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[50];
    int math;
    int science;
    int social;
    float avg;
}Student;

void write_student_data(Student *A){
    printf("name : ");
    scanf("%s",A->name);
    printf("math : ");
    scanf("%d",&A->math);
    printf("science : ");
    scanf("%d",&A->science);
    printf("social : ");
    scanf("%d",&A->social);
    A->avg = ( (float)((A->math) + (float)(A->science) + (float)(A->social))/3);
}

void print_student_data(FILE *fp, Student *A){
    
    fprintf(fp,"%s : ",A->name);
    fprintf(fp,"%d ",A->math);
    fprintf(fp,"%d ",A->science);
    fprintf(fp,"%d ",A->social);
    fprintf(fp,"%f ",A->avg);
    fprintf(fp,"\n");
}

void show_student_data(Student *A){
    
    printf("이름 : %s \n",A->name);
    printf("수학 : %d \n",A->math);
    printf("과학 : %d \n",A->science);
    printf("사회 : %d \n",A->social);
    printf("평균 : %f \n",A->avg);
    printf("\n");
}

void read_student_data(FILE *fp, Student *A){
    fscanf(fp,"%s :",A->name);
    fscanf(fp,"%d ",&A->math);    
    fscanf(fp,"%d ",&A->science);
    fscanf(fp,"%d ",&A->social);
    fscanf(fp,"%f ",&A->avg);
}

int main(){
    FILE *fp;
    fp = fopen("./score.txt","r");
    if(fp==NULL){
        printf("Wtire Error!!\n");
        return 0;
    }
    int num_student;

    fscanf(fp,"저장된 학생 : %d\n",&num_student);
    
    Student *list = (Student *)malloc(num_student * sizeof(Student));

    for(int i=0; i< num_student; i++){
        read_student_data(fp, (list+i) );
    }

    for(int i=0; i<num_student; i++){
        show_student_data((list+i));
    }

    fclose(fp);

    return 0;
}