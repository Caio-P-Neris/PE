// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista* Lista;

struct lista
{
    int num;
    Lista prox;
};


Lista cria_lista(){
    return NULL;
}

Lista add(Lista l, int x){
    Lista novo = malloc(sizeof(struct lista));
    novo->num = x;
    novo->prox = l;

    return novo;
}

void imprime(Lista l){
    while(l != NULL){
        printf("%d \n", l->num);
        l =  l->prox;
    }
}

void destroi(Lista *l){
    Lista atual = *l;
    Lista temp;
    while (atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
}

Lista inverte(Lista l){
    Lista atual = l;
    Lista anterior = NULL;
    Lista proximo;
    while (atual != NULL){
        proximo = atual->prox;
        
        atual->prox = anterior;
        anterior = atual;
        
        atual = proximo;
    }
    return anterior;
}

int main(){

    Lista l = cria_lista();

    printf("Digite quantos elementos quer adicionar \n");
    int n;
    scanf("%d", &n);
    int x;

    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        l = add(l, x);
    }

    printf("Imprime: \n");
    imprime(l);

    l = inverte(l);

    printf("inverso: \n");

    imprime(l);

    destroi(&l);

    // if (l != NULL)
    //     imprime(l);
    // else
    //     printf("destriu certo\n ");
    
    // return 0;
}