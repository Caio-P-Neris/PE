// tem que imprimir todo o conteudo de todos os arquivos txt informados 
// se fizer > saida.txt a saida tem que ter o conteudo acima 
// se fizer  < 
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

    //printf("n arg %d \n", argc);

    for(int i = 0; i < argc -1; i++){

    arq = fopen(argv[1 +i], "r");

    if (arq == NULL) {
    printf("Problema ao ler o arquivo.\n");
    return 1;
    }


    while( fscanf(arq, "%c", &aux) != EOF)
        printf("%c", aux);

    printf("\n");

    fclose(arq); 
    }

    return 0;
}