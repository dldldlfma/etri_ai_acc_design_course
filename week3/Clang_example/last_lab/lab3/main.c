#include <stdio.h>

int main(){
	float score;
	printf("score input : ");
	scanf("%f",&score);

	if(score>0 && score <100){
			if(score>50){
					printf("pass\n");
			}
			else{
					printf("fail\n");
			}
	}
	else{
		printf("wrong score\n");
	}

	return 0;
}

