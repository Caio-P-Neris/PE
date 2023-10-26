// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 1000

// isso daqui só quebrava quando chegava no caracter 80 sem se preocupar com as palavras
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

// ideia: fazer uma função que qubra o texto nos espaços e cria uma matriz (vetores dentro de um grande) em que cada vetor é uma palavra
// criar outra função que um novo vetor é a junção das palavras se essa junção não ultrapassa 80 caracteres

// int pega_palavras(int tamannho, char texto[MAX]){
//     int i, j =0, n_palavras = 0, palavra_atual = 0;
//     char palavras[MAX][MAX], palavra[MAX];

//     for (i = 0; i < tamannho; i++){
//         if ( texto[i] != 32 && texto[i] != '\0' ){
//             palavra[j] = texto[i];
//             j++;

//         } else if (texto[i] == 32){
//             palavra[j] = '\0';
//             strcpy(palavras[palavra_atual], palavra);
//             n_palavras += 1;
//             palavra_atual += 1;
//             j = 0;
//         }
//     }

//     if (j > 0) { //gambiarra para pegar a ultima palavra quando nao é seguida de um espaço sem mudar a logica acima
//         palavra[j] = '\0';
//         strcpy(palavras[palavra_atual], palavra);
//         n_palavras++;
//     }

//     // para visualizar quando tiver duvida se pegou todas palavras
//     // for (i = 0; i < n_palavras; i++) {
//     // printf("%s\n", palavras[i]);
//     // }

//     return n_palavras;
// }

// void novo_texto(char palavras[MAX][MAX], int n_palavras){
//     char linha[MAX][MAX];
//     int i;

//     for (i = 0; i < n_palavras; i++){
//         if (strlen(linha[i][i]) < 80){
//             linha[i][i] = palavras[i][i];
//         }else
//             printf("%s", linha);
//     }

// }

int main(){
    char texto[MAX];
    
    printf("Digite o texto \n");
    fgets(texto, MAX, stdin);

    // if (tamanho % 80 == 0){
    //     n_linhas = tamanho / 80;
    // } else
    //     n_linhas = (tamanho / 80) +1;

    //printf("%d\n", tamanho);
    //printf("%d\n", n_linhas);

    quebra_linha( texto);
    // n_palavras = pega_palavras(tamanho, texto);
    // novo_texto(palavras, n_palavras);
    return 0;
}