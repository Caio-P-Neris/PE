// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void inc(int *a){
    
    *a += 1;

}

int main(){

    int a;

    printf("Digite o inteiro a \n");

    scanf("%d", &a);

    inc(&a);

    printf("a: %d \n", a);

    return 0;
}