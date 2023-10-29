#include <stdio.h>
#include <string.h>

int main() {
    // Defina um vetor de strings
    char *strings[] = {"Esta", "e", "uma", "concatenacao", "de", "strings"};

    // Determine o tamanho total necessário para a nova string
    int tamanho_total = 0;
    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        tamanho_total += strlen(strings[i]);
    }
    // Adicione espaços em branco (um espaço por string) entre as strings
    tamanho_total += sizeof(strings) / sizeof(strings[0]) - 1;

    // Crie uma nova string com tamanho suficiente
    char resultado[tamanho_total + 1];  // +1 para o caractere nulo de terminação

    // Inicialize a nova string com uma string vazia
    resultado[0] = '\0';

    // Concatene as strings no vetor com espaços em branco
    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        strcat(resultado, strings[i]);
        if (i < sizeof(strings) / sizeof(strings[0]) - 1) {
            strcat(resultado, " "); // Adicione um espaço em branco, exceto após a última string
        }
    }

    // Imprima o resultado
    printf("String concatenada: %s\n", resultado);

    return 0;
}
