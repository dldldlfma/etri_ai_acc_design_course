#include <stdio.h>

int main()
{
	int student[11]={90,84,34,97,54,67,72,30,16,75,91};

	for(int i=0; i<11; i++)
	{
		printf("stduent[%d]의 주소 %x \n",i,&student[i]);
	}

	printf("%d, %d\n",&student[0], student);

	return 0;
}

