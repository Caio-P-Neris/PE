// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

void ordena(int valores[], int n){
    int j, i, sentinela;
    for ( i = 1; i < n; i++){
        sentinela = valores[i];
        j = i -1;
        while (j >= 0 && valores[j] > sentinela){
            valores[j+1] = valores[j];
            j -= 1;
        }
        valores[j + 1] = sentinela;
    }
    printf("Ordenado fica: \n");
    for (i = 0; i<n; i++)
        printf("%d\n", valores[i]);
}


int main(){
    int n, valores[100];
    printf("Quantos numeros tem o vetor? \n");
    scanf("%d", &n);

    printf("Digite os numeros do vetor: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &valores[i]);

    ordena(valores, n);
    return 0;
}