// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

void inverte(int n,char* word, int ini, int fim){

    if (ini >= fim){
        word[n] = word[n];
        //word[n+1] = '\0';
        return;
    }else{
        char temp = word[ini];
        word[ini] = word[fim];
        word[fim] = temp;
        
        inverte(n-1, word, ini+1, fim-1);
    }


    //word[n+1] = '\0';
}


int main(){

    int n;

    printf("Qual o numero de letras da palavra? \n");

    scanf("%d", &n);

    getchar();

    printf("Digite a palavra \n");

    char* word = malloc((n+1)*sizeof(char));

    fgets(word, n+1,stdin);

    inverte(n, word, 0, n-1); //n é o numero de letras real

    word[n] = '\0';

    printf("%s", word);

    free(word);
    return 0;
}

//abobora/0 
//01234567