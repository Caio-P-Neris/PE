// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void le_matriz(int n, int m,int matriz[100][100]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void soma_matriz(int A[100][100],int B[100][100],int C[100][100], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main(){
    int n, m, A[100][100], B[100][100], C[100][100];

    printf("Qual o numero n de linhas? ");
    scanf("%d", &n);

    printf("Qual o numero m de colunas? ");
    scanf("%d", &m);

    printf("Digite a matriz A: \n");
    le_matriz(n,m,A);

    printf("Digite a matriz B: \n");
    le_matriz(n,m,B);

    soma_matriz(A,B,C,n,m);

    printf("Matriz resultante C:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}