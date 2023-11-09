#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz de tamanho n x m
int** criarMatriz(int n, int m) {
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }
    return matriz;
}

// Função para ler uma matriz n x m do usuário
void lerMatriz(int **matriz, int n, int m) {
    printf("Digite os elementos da matriz %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para liberar a memória alocada para a matriz
void liberarMatriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int n, m;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    int **matriz = criarMatriz(n, m);
    lerMatriz(matriz, n, m);

    // Agora você pode usar a matriz para outras operações

    // Exemplo: Imprimir a matriz lida
    printf("Matriz %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória alocada para a matriz
    liberarMatriz(matriz, n);

    return 0;
}