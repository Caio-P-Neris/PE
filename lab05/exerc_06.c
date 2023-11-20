#include <stdio.h>
#include <stdlib.h>

void collatz(int n){
    if (n ==1){
        printf("%d\n", n);
        return;
    } else if (n % 2 == 0){
        printf("%d ", n);
        collatz(n/2);
    } else{
        printf("%d ", n);
        collatz(3*(n) +1);
    }
}

int main(){
    printf("Qual seu numero? \n");

    int n; 
    scanf("%d", &n);

    collatz(n);

    return 0;
}