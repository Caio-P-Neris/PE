// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Digite quantos n numeros serao lidos \n");

    scanf("%d", &n);

    int* vetor = malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){

        scanf("%d", &vetor[i]);

        printf("entrada %d, conteudo %d, endereco: %u \n", i, vetor[i], (unsigned int)&vetor[i]);

    }

    free(vetor);

    return 0;
}