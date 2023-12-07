//Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>

typedef struct no* Lista;

struct no{
    int num;
    Lista prox;
};

Lista cria_lista(){
    return NULL;
}
Lista add(Lista l, int x){
    Lista novo;
    novo = malloc(sizeof(struct no));
    novo->num = x;
    novo->prox = l;
    return novo;
}

Lista inverte(Lista l) {
    Lista atual = l;
    Lista anterior = NULL;
    Lista proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

void impressao(Lista l){
    if (l != NULL){
        printf("%d \n", l->num);
        impressao(l->prox);
    }
}

Lista destroir_lista(Lista l){
    Lista atual= l;
    Lista temp;
    while (atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    return atual;
}

int main(){

    Lista l1 = cria_lista();
    
    printf("Digite quantos numeros quer adicionar na lista \n");

    int n, num;

    scanf("%d", &n);

    printf("Digite os numeros \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
            
            l1 = add(l1, num);

    }

    printf("Lista original: \n");

    impressao(l1);

    Lista l = inverte(l1); 

    printf("Lista invertida: \n");

    impressao(l);

    l = destroir_lista(l);

   return 0;
}