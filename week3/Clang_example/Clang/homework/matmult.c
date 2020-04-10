#include <stdio.h>
#include <stdlib.h>

#define ZERO 0
#define SET 1

void matrix_init(int **arr, int size, int set){
    int temp;
    if(set ==SET){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                printf("%d %d : ",i,j);
                scanf("%d", &temp);
                *(*(arr+j)+i) = temp;
                printf("\n");
            }
        }
    }
    else if(set == ZERO){
        for (int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                *(*(arr +j) +i) =0;
            }
        }
    }
}

void show_matrix(int **arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d, ",*(*(arr+j)+i));
        }
        printf("\n");
    }
}

void matmul(int **A, int **B, int **out_Mat, int size){
    int i,j,k;

    for(i =0; i<size; i++){
        for(j=0; j<size; j++){
            for(k=0; k<size; k++){
                *(*(out_Mat+j)+i) += *(*(A +k)+i) * *(*(B +j) +k);
            }
        }
    }
}

void write_matrix(int **arr, int size, FILE* fp) {
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            fprintf(fp, "%d, ", *(*(arr +j)+i));
        }
        fprintf(fp,"\n");
    }
}

int main()
{
    int size, i;
    char select;

    printf("array size : ");
    scanf("%d", &size);

    int **arr = (int**)malloc(sizeof(int*)*size);
    for(i=0; i<size; i++){
        *(arr +i) = (int*)malloc(sizeof(int) *size);
    }

    int **arr2 = (int**)malloc(sizeof(int*)*size);
    for(i=0; i<size; i++){
        *(arr2 +i) = (int*)malloc(sizeof(int) *size);
    }

    int **output = (int**)malloc(sizeof(int*)*size);
    for(i=0; i<size; i++){
        *(output +i) = (int*)malloc(sizeof(int) *size);
    }

    printf("--- Matrix 1 ---\n");
    matrix_init(arr, size, SET);
    show_matrix(arr,size);

    printf("--- Matrix 2 ---\n");
    matrix_init(arr2, size, SET);
    show_matrix(arr2,size);

    matrix_init(output, size, ZERO);

    matmul(arr, arr2, output, size);

    printf("\n\n ----result---- \n\n");
    show_matrix(output, size);

    printf("\n\n Do you want to save?(y/n) : ");
    scanf(" %c", &select);

    if(select =='y'){
        FILE *fp;
        fp=fopen("./matmult.txt", "w");
        if(fp==NULL){
            printf("Write Error\n");
            return 0;
        }
        fprintf(fp,"\n ----- MatrixA -----\n");
        write_matrix(arr, size, fp);
        fprintf(fp,"\n ----- MatrixB -----\n");
        write_matrix(arr2, size, fp);
        fprintf(fp,"\n\n----- Output -----\n");
        write_matrix(output, size, fp);

        printf("\n\n ===Save Complete === \n\n");

    }
    else {
        printf("\n\n === Save Skip === \n");
    }

    for(int i=0; i< size; i++){
        free(*(arr +i));
        free(*(arr2 +i));
        free(*(output +i));
        
    }

    free(arr);
    free(arr2);
    free(output);

    return 0;
}