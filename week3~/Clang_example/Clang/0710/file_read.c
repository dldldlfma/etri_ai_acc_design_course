#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("./test.txt", "r");
    char words;

    while((words == fgetc(fp)) != EOF){
        printf("%c",words);
    }
    fclose(fp);
    return 0;
}