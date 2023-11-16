// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double raiz(double x){
    return sqrt(x);
}

void mapear(double array[], int n, double func(double)) {
    for (int i = 0; i < n; i++)
        array[i] = func(array[i]);
}

int main(){
    int n;

    printf("Vamos calcular a raiz quadrada de cada elemento de um vetor, digite primeiro quantos elementos tem o vetor \n");
    scanf("%d", &n);

    double *v = malloc(n* sizeof(int));

    printf("Digite o vetor\n");

    for(int i = 0; i < n; i++){
        scanf("%lf", &v[i]);
    }

    printf("A raiz fica \n");
    
    mapear(v, n, raiz);

    for (int i = 0; i < n; i++){
        printf("%.2f\n", v[i]);
    }

    free(v);
    return 0;
}