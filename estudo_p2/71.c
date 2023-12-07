// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

    if( argc < 2)
        printf("falaha ao ler arquivo \n");

    FILE* arq;

    arq = fopen(argv[1], "r");

    char aux;

    while (fscanf(arq, "%c", &aux) != EOF){
        printf("%c", aux);
    }

    printf("\n");

    fclose(arq);
    

    return 0;
}