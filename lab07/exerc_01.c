// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[]){

    FILE *arq;
    char aux;

    if (argc < 2){
        printf("Informe o nome do arquivo \n");
        
    }

    arq = fopen(argv[1], "r");

    if (arq == NULL) {
    printf("Problema ao ler o arquivo.\n");
    return 1;
    }
    
    int contador = 0;

    while( fscanf(arq, "%c", &aux) != EOF)
        if (aux == ' ' || aux == '\n')
        contador +=1;

    if (contador != 0) 
        contador +=1;  
    
    printf("%d\n", contador);

    fclose(arq); 

    return 0;
}