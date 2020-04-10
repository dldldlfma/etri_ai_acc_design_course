#include <stdio.h>

int main(){
    FILE *fp;
    fp=fopen("././test.txt","r");
    char words[20];
    if(fp == NULL){
        printf("Read Error!!\n");
        return 0;
    }

    while(fscanf(fp, "%s", words) != EOF){
        printf("%s ", words);
    }
    fclose(fp);
    return 0;
}