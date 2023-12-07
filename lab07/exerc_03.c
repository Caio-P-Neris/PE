// tambem precia ter parametro -n para imprimir a linha que achou a palavra
// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[]){

    FILE *arq;
    char aux[100];
    char caracter; 

    if (argc < 2){
        printf("Informe o nome do arquivo \n");
        
    }

    //printf("n arg %d \n", argc);

    for(int i = 1; i < argc -1 ; i++){ // começa em 1 pra pular palavra 

        char *palavra = malloc(sizeof(argv[1] +1 ));
        strcpy(palavra, argv[1]);

        //printf("arq %s ", argv[i +1]);
        //printf("%s \n", palavra);

        arq = fopen(argv[1 +i], "r");

        int conta_linha = 0;

        if (arq == NULL) {
            printf("Problema ao ler o arquivo.\n");
            return 1;
        }

        // while( fscanf(arq, "%c", &caracter) != EOF){
            
        //     if (caracter == '\n')
        //         conta_linha += 1;

        //     if( caracter == ' '){
        //         fscanf(arq, "%s", &aux);
            
        //         //printf("%s \n", aux);
        //         if (strcmp(palavra, aux) == 0){
        //             printf("nome do arquivo: %s ", argv[i +1]);
        //             printf("%d esta eh a linha que contem ", conta_linha);
        //             printf("\033[1;31m"); 
        //             printf("%s ", palavra);
        //             printf("\033[1;m");
        //             printf("dentro do arquivo \n");
        //         }
        //     }
        // }

        char palavra_dentro[100];
        while (fgets(&aux, strlen(aux), arq) != EOF){
            conta_linha +=1;
            
            for(int i = 0; aux[i] != ' '; i++){
                strcpy(palavra_dentro, aux[i]);
                
            }
        }

        printf("\n");

        fclose(arq); 
    }

    return 0;
}