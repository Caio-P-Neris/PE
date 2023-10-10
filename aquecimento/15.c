#include <stdio.h>
#define MAX_SIZE 8 // Tamanho máximo da lista

int main() {
    int lista[MAX_SIZE];
    int tamanho = 0;
    int maior, menor, diferenca;

    printf("Digite a lista de números separados por espaços (até %d elementos):\n", MAX_SIZE);

    while (tamanho < MAX_SIZE) {
        scanf("%d", &lista[tamanho]); {
        }
        tamanho++;
    }
    maior = lista[0];
    menor = lista[0];
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] > maior){
            maior = lista[i];
        } else if (lista[i] < menor){
            menor = lista[i];
        }
    }
    diferenca = maior - menor;
    printf("%d\n", diferenca);

    return 0;
}