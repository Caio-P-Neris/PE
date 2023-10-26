// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#define MAX 100


struct matriz {
    int lista[MAX][MAX];
    int nl_c;
    int linha[MAX];
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
            for (int j = 0; j < tamanho; j++){
                printf("%d ", matriz.lista[i][j]);
            }
            printf("\n");
        }
    }

    Matriz matriz_multiplica(Matriz matriz_a, Matriz matriz_b){
        Matriz resultado;
        int elemento, soma = 0;

        for (int i = 0; i < matriz_a.nl_c; i++){
            for ( int j = 0; j < matriz_b.nl_c; j++){
                soma = 0;

                for ( int b = 0; b < matriz_a.nl_c; b++ ){
                    elemento = matriz_a.lista[i][b] * matriz_b.lista[b][j];
                    soma += elemento;
                }
                
                resultado.lista[i][j] = soma;
            
        }
    }
        
        return resultado;
    }

int main(){
    int n;
    Matriz matriz_a, matriz_b, matriz_multiplicada;


    printf("Digite o tamanho n da matriz quadrada\n");
    scanf("%d", &n);

    printf("Digie cada elemento da primeira em linhas diferentes \n");
    matriz_a = matriz_le(n);    
    //imprime_matriz(matriz_a, matriz_a.nl_c);
    printf("Digie cada elemento da segunda em linhas diferentes \n");
    matriz_b = matriz_le(n); 

    matriz_multiplicada = matriz_multiplica(matriz_a, matriz_b);

    imprime_matriz(matriz_multiplicada, n);

    return 0;
}