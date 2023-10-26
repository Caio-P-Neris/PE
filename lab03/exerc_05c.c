// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 1000

// void junta(char texto[MAX][MAX], int n_frases, char texto_final[MAX]) {
//     int texto_final_nLetras = 0;

//     for (int i = 0; i < n_frases; i++) {
//         int taman = strlen(texto[i]);
//         if (taman > 0 && texto[i][taman - 1] == '\n') {
//             texto[i][taman - 1] = ' ';  // Substitui a nova linha por um espaço no final da frase.
//         }
//         strcpy(texto_final + texto_final_nLetras, texto[i]);
//         texto_final_nLetras += strlen(texto[i]);
//         if (i < n_frases - 1) {
//             texto_final[texto_final_nLetras] = ' ';
//             texto_final_nLetras++;
//         }
//     }
// }

void junta(char texto[MAX][MAX], int n_frases, char texto_final[MAX]) {
    texto_final[0] = '\0';  // Inicialize texto_final como uma string vazia

    for(int i = 0; i < n_frases; i++) {
        strcat(texto_final, texto[i]);
        if (i < n_frases - 1) {
            strcat(texto_final, " ");
        }
    }

    printf("%s", texto_final);
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
    printf("Digite o texto, para parar de digitar e o programa processar, digite numa linha apenas 0 \n");

    while(1){
        fgets(texto, MAX, stdin);
        //printf("%s", texto);

        if (texto[0] == '0'){
            break;
        }
       
       n_frases +=1;
        strcpy(texto_junto[i], texto);

    

        i+=1;
    }
    // for(int j = 0; 1; j++)
    //     for(i =0; texto_junto[i][i] != '\0'; i++ )
    //         printf("%s", texto_junto[i]);
    junta(texto_junto, n_frases, texto_final);
    quebra_linha(texto_final);
    return 0;
}