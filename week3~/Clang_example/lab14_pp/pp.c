#include <stdio.h>

int main(){
	int *p, **pp, a=3;

	p=&a;
	pp=&p;

	printf("%d\n",*p);
	printf("%d\n",&**pp);

	printf("%d\n",p);
	printf("%d\n",*pp);
	return 0;
}
