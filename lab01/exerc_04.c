// Caio Pereira Neris, RA: 11202230288
#include <stdio.h>
void produto_hadamard(double u[], double v[], double resultado[], int n){

    for (int i = 0; i < n; i++){
        resultado[i] = (u[i] * v[i])/1.0;
        printf("%lf\n" , resultado[i]); 
    }
}

int main(){
    int i, n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    double u[100], v[100], resultado[100];
    
    printf("Coloque os valores do vetor u:\n");
    for (i = 0; i <n; i++)
        scanf("%lf", &u[i]);
    printf("Coloque os valores do vetor v:\n");
    for (i = 0; i < n; i++)
        scanf("%lf", &v[i]);
    
    produto_hadamard(u, v, resultado, n);

    return 0;
}