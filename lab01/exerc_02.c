// Caio Pereira Neris, RA: 11202230288
#include <stdio.h>

int main(){
    int j, n, i, acc = 0;
    scanf("%d", &n);
    for (i = 2; i <= n ; i++){
        acc = 0;
        for (j = 1; j <= i; j++){
            if (i % j == 0){
                acc += 1; 
            }
        }
        if (acc == 2)
            printf("%d\n", i);
    }
    return 0;
}