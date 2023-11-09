// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* revert(char* s){
    int size = strlen(s);

    char *invertido = malloc(size*(sizeof(char)));

    int j=0;

    for (int i = size -2; i >= 0; i--){ // -2 para tirar o \n
        //if(s[i] != '\n'){
            *(invertido + j) = s[i];
            //printf("%c\n", invertido[j]);
            j++;
        //}
    }

    invertido[j] = '\0';

    return invertido;

}

int main(){

    size_t taman = 0;

    char *s = NULL;

    printf("Digite a string: \n");

    getline(&s, &taman, stdin);

    char *invertido = revert(s);

    printf("%s", invertido);


    free(invertido);
    free(s);
    return 0;
}