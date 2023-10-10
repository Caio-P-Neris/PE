// Caio Pereira Neris, RA: 11202230288
#include <stdio.h>

// lê n inteiros fornecidos pelo usuário e armazena -os no vetor entrada
void le_vetor(int entrada[], int n){
    printf("Digite a sequencia\n");
    for (int i =0; i < n; i++){
        scanf("%d", &entrada[i]);
    } 
}
// retorna o valor mínimo do vetor v que tem n elementos
int minimo(int v[], int n){
    int min = v[0];
    for (int i = 1; i < n; i++)
        if(v[i] < min)
            min = v[i];
    return min;
}
// retorna o valor máximo do vetor v que tem n elementos
int maximo(int v[], int n){
    int max = v[0];
    for (int i = 1; i < n; i++)
        if(v[i] > max)
            max = v[i];
    return max;
}

// retorna a média dos elementos guardados em um vetor v de n elementos
double media(int v[], int n){
    int soma = 0;
    for (int i = 0; i < n; i++){
        soma += v[i];
    }
    double med = soma /(n*1.0);

    return med;
}

int main(){
    
    int n, entrada[100];
    printf("A sequencia possui quantos numeros? (numero maximo: 100) ");
    scanf("%d", &n);
    
    le_vetor(entrada, n);
    
    int min = minimo(entrada, n);
    int max = maximo(entrada, n);

    printf("Minimo: %d\n", min);
    printf("Maximo: %d\n", max); 

    double medi = media(entrada, n);
    printf("Media: %lf\n", medi);

    return 0;
}