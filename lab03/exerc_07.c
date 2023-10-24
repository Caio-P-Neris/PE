// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#define MAX 100


struct matriz {
    int lista[MAX][MAX];
    int nl_c;
};

typedef struct matriz Matriz;


Matriz matriz_le(int n){
    Matriz matriz_fim;
    matriz_fim.nl_c = n;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &matriz_fim.lista[i][j]);
            // matriz_fim.tamanho += 1;
        }
    }
    return matriz_fim;
}

    void imprime_matriz(Matriz matriz, int tamanho){
        for (int i = 0; i < tamanho; i++){
            for (int j = 0; j < tamanho; j++)
                printf("%d ", matriz.lista[i][j]);
                printf("\n");
        }
    }

int main(){
    int n;
    Matriz matriz_a;


    printf("Digite o tamanho n da matriz quadrada\n");
    scanf("%d", &n);

    matriz_a = matriz_le(n);    
    imprime_matriz(matriz_a, matriz_a.nl_c);

    return 0;
}