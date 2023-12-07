// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverte(char word[], int ini, int fim){

    if(ini >= fim){
        return word;
    } else{
        char temp = word[ini];
        word[ini] = word[fim];
        word[fim] = temp;
        return inverte(word, ini +1, fim -1);
    }

}

int main(){

    int n;
    printf("Quantas letras tem sua palavra ? \n");
    scanf("%d", &n);

    getchar();

    char* word = malloc((n+1)*sizeof(char));

    fgets(word, n+1, stdin);

    //printf("%s", word);

    char* inverso = malloc((n+1)*sizeof(char)); 
    inverso = inverte(word, 0, n-1);

    printf("%s", inverso);

    free(word);
    free(inverso);

    return 0;
}