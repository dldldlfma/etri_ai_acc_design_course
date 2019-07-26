#include <stdio.h>

int main(){
    char word[50];
    printf("Space 없이 50자 이내 문자열 입력하세요\n: ");
    scanf("%s", word);

    printf("입력 받은 문자열 : %s", word);

    int check;
    int num=0;
    while(check==NULL){
        if(word[num]!=NULL){
            num++;
        }else{
            break;
        }
        
    }
    printf("\n\n 문자열 길이 : %d \n",num);
    return 0;
}