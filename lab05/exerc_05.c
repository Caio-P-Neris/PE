// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

int torre(int n){
    if(n ==1)
        return 1;
    else{
        return 2 * torre(n-1) +1;
    }

}

int main(){
    int n;
    printf("Quantos discos tem? \n");

    scanf("%d", &n);

    int movimentos = torre(n) ;

    printf("sao necessarios %d movimentos para mover %d discos\n", movimentos, n);
}
// discos 1 2 3 4
//mov     1 3 7 15  