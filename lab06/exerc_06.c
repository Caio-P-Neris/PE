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

void add(Lista *l, int x){

    Lista novo = malloc(sizeof(struct no));
    novo->num = x;

    novo->prox = *l;    
    *l = novo;
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

    Lista l = cria_lista();
    printf("Digite quantos numeros quer adicionar numa lista \n");

    int n, num;

    scanf("%d", &n);

    printf("Digite os numeros \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
            
            add(&l, num);

    }

    printf("A lista que voce digitou e \n");

    impressao(l);

    l = destroir_lista(l);
}