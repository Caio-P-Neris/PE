// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 100

int confere(char palavra[MAX], char palavra_daFrase[MAX]){
    int i;

    for (i = 0; palavra[i] != '\0' && palavra_daFrase[i] != '\0'; i++){
        if(palavra[i] != palavra_daFrase[i]){
            return 0; 
        }
    }

    return 1; 
}

void divide_frase(char frase[MAX], char palavra[MAX]){
    int tamanho = strlen(frase), i, j = 0, n_palav = 0;
    char palavra_daFrase[MAX];

    for (i = 0; i < tamanho; i++) {
        if (frase[i] == ' ' || frase[i] == '\n') {
            palavra_daFrase[j] = '\0'; 
            int resultado = confere(palavra, palavra_daFrase);
            if (resultado == 1) {
                printf("Sim\n");
                return; // gambiarra para nao imprimir sim e nao varias vezes
            }
            j = 0; 
            n_palav++;
        } else {
            palavra_daFrase[j] = frase[i];
            j++;
        }
    }

    printf("Nao\n"); 
}

int main(){
    char palavra[MAX], frase[MAX];

    printf("Digite uma palavra: \n");
    fgets(palavra, MAX, stdin);

    printf("Digite uma frase: \n");
    fgets(frase, MAX, stdin);

    divide_frase(frase, palavra);

    return 0;
}