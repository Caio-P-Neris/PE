// Caio Pereira Neris RA: 11202230288
#include <stdio.h>

int busca(int valores[], int n, int chave){
    for( int i = 0; i < n; i++){
        if (valores[i] == chave)
            return i;
    }
    return -1;
}

int main(){
    int n, chave, valores[100];
    printf("Quantos numeros tem o vetor? \n");
    scanf("%d", &n);

    printf("Digite os numeros do vetor: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &valores[i]);
    

    printf("Qual sua chave? \n");
    scanf("%d", &chave);

    printf("%d", busca(valores, n, chave));


    return 0;
}