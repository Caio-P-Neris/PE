// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 100

// modulo da distancia de maiusc e minusc é 32 
void converte(char frase[MAX], int tamanhof, char nova_frase[MAX]){
    int i;
    for (i = 0; i < tamanhof; i++){
        if (frase[i] < 96 && frase[i] > 64 ){
            nova_frase[i] = (frase[i] + 32);
        } else if(frase[i] == 32 ){
            nova_frase[i] = frase[i];
        } else{
            nova_frase[i] = (frase[i] - 32);
        }
    }
    nova_frase[tamanhof] = '\0';
}

int main(){
    int tamanhof ;
    char frase[MAX], nova_frase[MAX];

    printf("Digite a frase: \n");
    fgets(frase, MAX, stdin);
    tamanhof = strlen(frase) -1;

    converte(frase, tamanhof, nova_frase);

    printf("%s \n", nova_frase);


    return 0;
}