// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* concatena(char* a, char* b, int Ta, int Tb){

    char* concatenado = malloc((Ta + Tb)*sizeof(char));

    a[Ta-1] = ' ';

    for (int i = 0; i < Ta; i++ )
        concatenado[i] = a[i];

    for (int j = 0; j < Tb -1; j++)
        concatenado[Ta + j] = b[j];

    return concatenado;
}

int main(){

    char* a = NULL;
    char* b = NULL;
    size_t ta, tb;

    printf("String a: \n");

    getline(&a, &ta, stdin);

    printf("String b: \n");

    getline(&b, &tb, stdin);

    printf("string a: %s \n", a);

    printf("string b: %s \n", b);


    int Ta = strlen(a);

    int Tb = strlen(b);

    //printf("ta %d tb %d", Ta, Tb);

    char* r = malloc(Ta * sizeof(char));

    r = concatena(a, b, Ta, Tb);

    printf("%s \n", r);

    return 0;
}