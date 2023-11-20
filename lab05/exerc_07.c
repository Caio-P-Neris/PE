#include <stdio.h>

int func(int n, int k){
    if (k == 0){
        return 1;
    } else{
        return func(n-1, k-1) + func(n-1, k);
    }

}

int main(){
    int n, k;
    printf("Digite n \n");
    scanf("%d", &n);

    printf("Digite k \n");
    scanf("%d", &k);

    int resp = func(n,k);

}