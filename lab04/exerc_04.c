// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *b;

    *b = *a;

    *a = temp;

}

int main(){

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    printf("Digite o inteiro a \n");

    scanf("%d", &a[0]);

    printf("Digite o inteiro b \n");

    scanf("%d", &b[0]);

    swap(a,b);

    printf("a: %d \n", a[0]);
    printf("b: %d \n", b[0]);

    free(a);
    free(b);


    return 0;
}