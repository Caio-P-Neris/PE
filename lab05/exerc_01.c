#include <stdio.h>

void count_down(int n){
    if (n == 1){
        printf("%d\n", n);
        printf("ACABOU!\n");
    } else{
        printf("%d\n", n);
        count_down(n-1);
    }
}



int main(){

    printf("Digite quanto quer contar \n");

    int n;

    scanf("%d", &n);

    count_down(n);

    return 0;
}