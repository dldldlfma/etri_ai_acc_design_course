#include <stdio.h>
#include <stdlib.h>

int odd(int a){

	int flag;

	if(a%2 ==1) flag=1;
	else flag=0;
	return flag;
}

int main(argc, char *argv[]){

	if(argc ==1){
		printf("no option error\n");
		exit(1);
	}

	int val = atoi(argv[1]);
	printf("odd : %d\n",odd(val));
	return 0;
}

