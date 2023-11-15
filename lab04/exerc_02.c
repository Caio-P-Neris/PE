// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Digite quantos n numeros serao lidos \n");

    scanf("%d", &n);

    int* vetor = malloc(n * sizeof(char));

    getchar();

    for(int i = 0; i < n; i++){

        char entrada = getchar();

        vetor[i] = entrada;

        char c;
        while ((c = getchar()) != '\n') {}

        printf("entrada %d, conteudo %c, endereco: %lld \n", i, vetor[i], (long long int)&vetor[i]);

    }

    free(vetor);

    return 0;
}