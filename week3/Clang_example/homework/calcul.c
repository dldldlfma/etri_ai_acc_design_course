#include <stdio.h>

int main(){

	int a,b;
	char operator;
	printf("set operator : ");
	scanf("%c",&operator);

	printf("set A :");
	scanf("%d",&a);

	printf("set B :");
	scanf("%d",&b);

	switch(operator){
		case '+': plus(a,b); break;
		case '-': minus(a,b); break;
		case '*': mult(a,b); break;
		case '/': div(a,b); break;
		case '%': remainder(a,b); break;

	}


	return 0;
}



void plus(int a, int b)
{
	printf("%d + %d = %d\n",a,b,a+b);

}

void minus(int a, int b)
{
	printf("%d - %d = %d\n",a,b,a-b);
}

void mult(int a, int b)
{
	printf("%d x %d = %d\n",a,b,a*b);
}

void div(int a, int b)
{
	printf("%d / %d = %d\n",a,b,a/b);

}

void remainder(int a, int b)
{
	printf("%d %% %d = %d\n",a,b,a%b);
}



