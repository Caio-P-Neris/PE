// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *b;

    *b = *a;

    *a = temp;

}

int main(){

    int a, b;

    printf("Digite o inteiro a \n");

    scanf("%d", &a);

    printf("Digite o inteiro b \n");

    scanf("%d", &b);

    swap(&a,&b);

    printf("trocado: \n");

    printf("a: %d \n", a);
    printf("b: %d \n", b);

    return 0;
}