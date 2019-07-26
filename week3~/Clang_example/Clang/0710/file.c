#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("./test.txt","w");
    if(fp==NULL){
        printf("Wtire Error!!\n");
        return 0;
    }

    fprintf(fp, "hwllo world!!\n");
    fclose(fp);

    return 0;
}