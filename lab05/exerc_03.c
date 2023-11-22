// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int n){
    if (n ==0)
        return v[0];
    else{
        return v[n] + soma(v, n-1);
    }
}

int main(){

    int n; 

    printf("Digite a quantidade de numeros\n");

    scanf("%d", &n);

    int *v = malloc(n*sizeof(int));

    printf("Digite os numeros do vetor \n");

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    int resultado = soma (v, n-1);

    printf("%d\n", resultado);

    free(v);
    return 0;
}