// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int **b){

    int *temp = *b;

    *b = *a;

    *a = temp;
    

}

int main(){

    int n, m, taman, i;

    printf("Vou ler dois vetores para invert-los entre si e ao final imprimir \n");

    printf("Primeiramente digite o tamanho de cada um  dos vetores como indicado \n");

    printf("Quantos numeros tem o vetor a? \n");

    scanf("%d", &n);

    printf("Quantos numeros tem o vetor b? \n");

    scanf("%d", &m);

    if (n > m)
        taman = n;
    else
        taman = m;

    int *a = (int *)calloc(taman, sizeof(int));

    int *b = (int *)calloc(taman, sizeof(int));


    printf("Digite cada numero do vetor a numa linha: \n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);


    printf("Digite cada numero do vetor b numa linha: \n");

    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    swap(&a,&b);

    printf("a ficou: \n");
    for(i = 0; i <m; i++)
        printf("%d, ", *(a + i));

    printf("\n");

    printf("b ficou: \n");

    for(i = 0; i < n; i++)
        printf("%d, ", * (b + i));

    free(a);
    free(b);


    return 0;
}
