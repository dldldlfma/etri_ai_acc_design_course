#include <stdio.h>

int main()
{
	double k,e,m;

	double avg;
	
	printf("k : ");
	scanf("%lf",&k);

	printf("e : ");
	scanf("%lf",&e);

	printf("m : ");
	scanf("%lf",&m);


	avg = (k+e+m)/3;

	printf("avg : %lf \n",avg);

	if(avg>=90){
		printf("장학생\n");
	}
	else if(avg>=50){
		printf("수고\n");
	}
	else if(avg<50)
	{
		printf("경고\n");
	}

	if(k>=95 && m>=95 && e>=95){
		printf("특별장학생\n");
	}
	return 0;
}
















