#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n;

    printf("\n M x N : "  );
    scanf("%d %d",m,n);

    char **pm = (char **)malloc(sizeof(char*) * m);
    
    
    char *pn = (char *)malloc(sizeof(char) * n);


    printf("%d %d", m,n);


    return 0;
}