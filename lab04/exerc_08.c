// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *cartesiano(int *v1, int n1, int *v2, int n2){

    int *vf = malloc(2*n1*n2*(sizeof(int)));

    int indice = 0;

    for (int i = 0; i < n1; i++){
        for ( int j = 0; j< n2; j++){
            *(vf + indice) = v1[i];
            indice++;
            *(vf + indice) = v2[j];
            indice++;
        }
    }

    return vf;
}

int main(){

    int n1, n2,i;

    printf("Quantos numeros tem o primeiro vetor? \n");

    scanf("%d", &n1);

    int *v1 = malloc(n1*sizeof(int));

    printf("Digite o primeiro vetor: \n");

    for (i = 0; i < n1; i++){
        scanf("%d", &v1[i]);
    }

    printf("Quantos numeros tem o segundo vetor? \n");

    scanf("%d", &n2);

    int *v2 = malloc(n2*sizeof(int));

    printf("Digite o segundo vetor: \n");

    for (i = 0; i < n2; i++){
        scanf("%d", &v2[i]);
    }

    int *vetor = cartesiano(v1, n1, v2, n2);

    int taman = 2*n1*n2;

    printf("O produto cartesiano fica: \n");
    for(i = 0; i < taman; i+= 2){
        printf("{%d, %d} \n", vetor[i], vetor[i+1]);
    }

    free(vetor);
    free(v1);
    free(v2);
    return 0;
}