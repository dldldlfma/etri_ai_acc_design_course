#include <stdio.h>

int main()
{
	int val;
	printf("input value : ");
	scanf("%d",&val);

	printf("odd : %d\n",odd(val));


	return 0;
}

int odd(int a){

	int flag;

	if(a%2 ==1) flag=1;
	else flag=0;
	return flag;
}
