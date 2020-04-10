#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[50];
	char math[10];
	char science[10];
	char social[10];
	char avg[10];
}Student;

void student_list(Student* A, int len){
	for(int i=0; i < len; i++){
		printf("이름 : %s ",A[i].name);
		printf("수학 : %s ",A[i].math);
		printf("과학 : %s ",A[i].science);
		printf("사회 : %s ",A[i].social);
		printf("평균 : %s \n",A[i].avg);
	}
}

int main(){
	FILE *fp;
	int num_student, trash;
	char standard[20];

	fp=fopen("./student.txt", "r");

	fscanf(fp, "저장된 학생 수 : %d",&num_student);

	Student* list = (Student*)malloc(num_student *sizeof(Student) );

	for(int i=0; i< num_student; i++){
		fscanf(fp, "%s", list[i].name);
		fscanf(fp, "%s", list[i].name);

		for(int j=0; j<4; j++){
			fscanf(fp, "%s", standard);
			if(strcmp(standard,"수학점수:")==0){
				fscanf(fp,"%s", list[i].math);
			}else if(strcmp(standard,"과학점수:")==0){
				fscanf(fp,"%s",list[i].science);
			}else if(strcmp(standard,"사회점수:")==0){
				fscanf(fp,"%s",list[i].social);
			}else if(strcmp(standard,"평균:")==0){
				fscanf(fp,"%s",list[i].avg);
			}
		}
	}

	student_list(list,num_student);
	free(list);
	fclose(fp);
	return 0;
}





