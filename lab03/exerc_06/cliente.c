// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include "conjunto.h"
#define MAX 100

void le_vetor(int tamanho, int vet[MAX] ){
    int i;
    for (i = 0; i < tamanho; i++)
        scanf("%d", & vet[i]);
}

int main(){
    int tamanho, vet[MAX], v1[MAX], v2[MAX], a;
    Conjunto con_a, con_b, unido;

    printf("Digite quantos numeros tem ambos conjuntos: \n");
    scanf("%d", &tamanho);

    con_a.tamanho = tamanho;
    con_b.tamanho = tamanho;

    printf("digite o primeiro conjunto \n");
    le_vetor(tamanho, v1);
    printf("digite o segundo conjunto \n");
    le_vetor(tamanho, v2);
    con_a = conjunto(v1, tamanho);    
    con_b = conjunto(v2, tamanho);


    printf("A uniao fica: \n");
    unido = conjunto_uniao(con_a, con_b);

    le_conjunto(unido);
    printf("\n");
    // printf("Qual numero voce gostaria de verificar se  pertence ao conjunto A? \n");
    // scanf("%d", &a);

    // printf("Se a seguinte linha retornar 1, ele percente. Se retornar 0, nao pertence \n");
    // conjunto_pertence(a, con_a);

    return 0;
}

