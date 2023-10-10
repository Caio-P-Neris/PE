// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void le_matriz(int n, int m,int matriz[100][100]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void transposta(int n, int m,int A[100][100], int T[100][100]){
    for (int i = 0; i <m; i++)
        for (int j = 0; j < n; j++){
            T[i][j] = A[j][i];
        }
}

void imprime_matrizT(int m, int n, int T[100][100]){
    for (int i = 0; i <m; i++){
        for (int j = 0; j < n; j++)
        printf("%d ", T[i][j]);
    printf("\n");
    }
}
int main(){
    int n, m, A[100][100], T[100][100];

    printf("Qual o numero n de linhas? ");
    scanf("%d", &n);

    printf("Qual o numero m de colunas? ");
    scanf("%d", &m);

    printf("Digite a matriz A: \n");
    le_matriz(n,m,A);

    transposta(n,m,A,T);

    printf("A matriz transposta e: \n");
    imprime_matrizT(m,n,T);

    return 0;
}