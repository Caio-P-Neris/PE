// Caio Pereira Neris RA : 11202230288
#include <stdio.h>
#include <string.h>

#define MAX 100

int maior_seq(int seq_zero[MAX], int tamanho){
    int i, maior;

    maior = seq_zero[0];

    for ( i = 0; i < tamanho; i++ ){
        if (seq_zero[i] > maior)
            maior = seq_zero[i];
    }
    return maior;
}

int main(){
    char texto[MAX];
    int i, tamanho, seq_zero[MAX] = {0}, maior;
    int acc = 0;
    
    printf("Digite seu texto \n");
    fgets(texto,MAX,stdin);

    tamanho = strlen(texto); // tem um a mais por causa do '\0'

    

    for (i = 0; i < tamanho; i++ ){
        if (texto[i] == '0' ){
            acc +=1;
        }
        else{
            seq_zero[i] = acc;
            acc = 0;
        }
    }

    maior = maior_seq(seq_zero, tamanho);

    printf("%d", maior);

    return 0;
}