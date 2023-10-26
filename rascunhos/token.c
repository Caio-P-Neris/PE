#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Esta é uma string,que,vamos,dividir";
    char *delimiters = " ,"; // Espaço em branco e vírgula como delimitadores

    char *token = strtok(str, delimiters);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters); // Esta chamada atualiza o token para o próximo na próxima iteração
    }

    return 0;
}