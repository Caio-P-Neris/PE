// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void le_matriz(int n, int m,int matriz[100][100]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void nova_matriz(int A[100][100], int i, int j, int n, int m, int nova[100][100]){
    for (int a = 0; a <n; a++){
        for (int b =0 ; b < m; b++){
            if (a == i)
                nova[a][b] = A[j][b];

            else if (a == j)
                nova[a][b] = A[i][b];
            
            else
                nova[a][b] = A[a][b];
        }
    }
}

void imprime_matriz(int n, int m, int nova[100][100]){
    for (int i = 0; i <n; i++){
        for (int j = 0; j < m; j++)
        printf("%d ", nova[i][j]);
    printf("\n");
    }
}

int main(){
    int i, j, n, m, A[100][100], nova[100][100];

    printf("Qual o numero n de linhas? ");
    scanf("%d", &n);

    printf("Qual o numero m de colunas? ");
    scanf("%d", &m);

    printf("Digite a matriz A: \n");
    le_matriz(n,m,A);

    printf("Qual linha i vc deseja que seja trocada?\n ");
    scanf("%d", &i);

    printf("Por qual linha j?\n ");
    scanf("%d", &j);
    
    nova_matriz(A,i,j,n,m,nova);
    imprime_matriz(n,m,nova);

    return 0;
}