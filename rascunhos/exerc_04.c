// Caio Pereira Neris
#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
    int i, sim, tamanhop, j, acc = 0, tamanhof;
    char frase[MAX], palavra[MAX];

    printf("DIgite a frase: \n");
    fgets(frase, MAX, stdin);
    tamanhof = strlen(frase); // tem um a mais por causa do '\0'

    printf("Digite a palavra \n");
    fgets(palavra, MAX, stdin);
    tamanhop = strlen(palavra);

    for (i = 0; i < tamanhop; i++)
    {
        for (j = 0; j < tamanhof; j++)
        {
            if (palavra[i] == frase[j])
            {
                acc += 1;
                break; // para sair do j quando encontrar a letra igual na frase
            }
        }
        if (acc == (tamanhop -1)){
            sim = 1;
            break;
        }
    }

    if (sim == 1)
        printf("Sim");
    
    else
        printf("Nao");

    return 0;
}