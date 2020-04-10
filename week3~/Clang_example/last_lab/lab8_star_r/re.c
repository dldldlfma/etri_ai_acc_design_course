#include <stdio.h>

int main()
{
	int i,j;
	int num;
	j=0;

	printf("input num : ");
	scanf("%d",&num);

	i=num;

	while(i>=0){
		while(j<i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		j=0;
		i--;
	}
	return 0;
}
