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


void compara(int n, int m, int A[100][100], int T[100][100]){
    int acc =0;
    for (int i = 0; i <m; i++)
        for (int j = 0; j < n; j++){
            if (T[i][j] == A[i][j])
                acc +=1;
    }

    if (acc == (n*m) )
        printf("Sim, e simetrica");
    else
        printf("Nao e simetrica");
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

    compara(n,m,A,T);


    return 0;
}