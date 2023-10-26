// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#define MAX 100

int procura(char texto[MAX], char carac){
    int i, lugar = -1; 
    for (i = 0; texto[i] != '\0'; i++){
        if (texto[i] == carac){
            lugar = i;
            break;
            return lugar;
        }
    }
    return lugar;
}

void nova_frase(char texto[MAX], int lugar, char final[MAX]){
    int i;
    for (i = 0; i < lugar; i++){
        final[i] = texto[i];
    }
    final[lugar] = '\0';
}

int main(){
    char texto[MAX], carac, final[MAX];
    int lugar;

    printf("Digite o caractere: \n");
    carac = getchar();
    printf("Digite a frase: \n");
    getchar();
    fgets(texto, MAX, stdin);


    lugar = procura(texto, carac);

    if (lugar == -1){
        printf("Não achei seu caractere, a frase fica da forma informada: \n");
        printf("%s", texto);
    } else{
        nova_frase(texto, lugar, final);
        printf("%s \n", final);
    }

    return 0;
}