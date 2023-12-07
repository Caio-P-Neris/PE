// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int* vetor, int n){
    if (n == 1){
        return vetor[0];
    } else
        return vetor[n-1] + soma(vetor, n-1);
}

int main(){

    int n;

    printf("Digite n \n");
    scanf("%d", &n);

    int* vetor = malloc(n*sizeof(int));
    int x;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        vetor[i] = x;
    }

    int r = soma(vetor, n);

    printf("%d", r);

    free(vetor);

    return 0;
}