// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void count_up(unsigned int n){
   if (n == 1)
    printf("%d\n", n);
    else{
        count_up(n-1);
        printf("%d\n", n);
    }
}



int main(){

    printf("Digite quanto quer contar \n");

    unsigned int n;

    scanf("%u", &n);

    count_up(n);

    return 0;
}