// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 1000

void junta(char texto[MAX][MAX], int n_frases, char texto_final[MAX]) {
    texto_final[0] = '\0';  

    for(int i= 0; i < n_frases  ; i++  ){
        strcat(texto_final, texto[i]);
        if (i < n_frases -1 )
            strcat(texto_final, " ");
    }
}


void quebra_linha( char texto[MAX]){
    int i =80 , j= 0;
    int tamanho = strlen(texto);
    
    while (i + j < tamanho){
        while( texto[i + j] != 32 ){
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

    int i =0, n_frases = 0;
    char texto[MAX], texto_junto[MAX][MAX], texto_final[MAX];
    printf("Digite o texto, para parar de digitar e o programa processar, apenas aperte enter sem mais nada na linha \n");

    while(1){
        fgets(texto, MAX, stdin);
        //printf("%s", texto);

        if (texto[0] == '\n'){
            break;
        }
       
       n_frases +=1;

       for (int i =0; texto[i] != '\0'; i++){
        if(texto[i] == '\n'){
            texto[i] = '\0';
        }
       }
        strcpy(texto_junto[i], texto);

        i+=1;
    }

    junta(texto_junto, n_frases, texto_final);
    quebra_linha(texto_final);
    return 0;
}