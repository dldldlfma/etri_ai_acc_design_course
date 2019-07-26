#include <stdio.h>

int main()
{
	int i=0;
	int student[5]={0,};
	double avg=0;

	for(i=0; i<5; i++){
		printf("student %d번째 성적",i+1);	
		scanf("%d", &student[i]);
		printf("\n");
	}

	for(i=0; i<5; i++){
		printf("student %d번째 ",i+1);	
		if(student[i]>=60){
			printf("합격\n");
		}else{
			printf("불합격\n");
		}
		avg+=(double)student[i];
	}

	printf("avg : %lf", avg/5);


	return 0;
}

