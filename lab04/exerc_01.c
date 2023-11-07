// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Digite quantos n numeros serao lidos \n");

    scanf("%d", &n);

    int* vetor = malloc(n * sizeof(int));

    int soma = 0;

    for(int i = 0; i < n; i++){
        printf("digite o %d numero\n", i+1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];

    }

    double media = soma / (n *1.0);

    printf("a media e %.2f\n", media);


    free(vetor);
    return 0;
}