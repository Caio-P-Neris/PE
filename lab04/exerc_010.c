// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matriz_le(int n, int m){

    int i;
    int **matriz = malloc(n*sizeof(int));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i <n; i++){
        for(int j = 0; j <m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}

void matriz_print(int **M, int n, int m){

    printf("sua matriz e: \n");

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++ )
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void matriz_liberar(int **M, int n){

    for(int i = 0; i < n; i++) {
        free(M[i]); 
    }
    free(M); 
}

int main(){

    int n, m;

    printf("Digite o numero de linhas: \n");
    scanf("%d", &n);

    printf("Digite o numero de colunas: \n");
    scanf("%d", &m);

    int **M = matriz_le(n,m);

    matriz_print(M, n, m);

    matriz_liberar(M,n);

    return 0;
}