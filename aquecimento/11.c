#include <stdio.h>

int main(){
    int n, ps, tq, res, contador;
    double soma;
    scanf("%d",&n);
    ps = n / 100, tq = n % 100;
    soma = ps + tq;
    res = soma * soma;
    if (res == n){
        printf("sim\n");
    } else {
        printf("não\n");
    }
    return 0;
}

