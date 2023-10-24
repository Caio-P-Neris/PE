// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#define MAX 100

int procura(char texto[MAX], char carac[MAX]){
    int i, lugar; 
    for (i = 0; texto[i] != '\0'; i++){
        if (texto[i] == carac[0]){
            lugar = i;
            break;
            return lugar;
        }else{
            return -1;
        }
    }
}

void nova_frase(char texto[MAX], int lugar, char final[MAX]){
    int i;
    for (i = 0; i < lugar; i++){
        final[i] = texto[i];
    }
    final[lugar] = '\0';
}

int main(){
    char texto[MAX], carac[MAX], final[MAX];
    int i, lugar;

    printf("Digite o caractere: \n");
    fgets(carac, MAX, stdin);
    printf("Digite a frase: \n");
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