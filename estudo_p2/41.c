#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("Digite n \n");

    scanf("%d", &n);

    int* numeros = calloc(n, sizeof(int));

    int soma = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("media %d\n", (soma/n));

    free(numeros);

    return 0;



}