// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* revert(char* s){
    int tf = strlen(s) + 1;

    char* inverso = malloc(tf*sizeof(char));

    for(int i = 0; i < tf; i++){
        inverso[i] = s[tf - i - 2];
    }

    inverso[tf] = '\0';

    return inverso;
}

int main(){

    int t;

    printf("Qual tamanho string ? \n");

    scanf("%d", &t);

    getchar();

    char* string = malloc((t+1)*sizeof(char));

    fgets(string, t+1, stdin);

    //printf("%s", string);

    char* r= revert(string);

    printf("%s\n", r);

    free(string);
    free(r);

    return 0;
}