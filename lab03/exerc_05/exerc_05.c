// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 1000

void quebra_linha( char texto[MAX]){
    int i =80 , j= 0;
    
    while (i + j < strlen(texto)){
        while( texto[i + j] != 32){
            i--;
        }
        texto[i + j] = '\n';
        j += i;
        i = 80;
    }
    printf("Mudado fica : \n");
    printf("%s", texto);
}

int main(){
    char texto[MAX];
    
    printf("Digite o texto \n");
    fgets(texto, MAX, stdin);

    quebra_linha( texto);

    return 0;
}