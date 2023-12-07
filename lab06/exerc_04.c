// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void impressao(Lista l){
    if (l != NULL){
        printf("%d \n", l->num);
        impressao(l->prox);
    }
}

Lista remover(Lista l, int x, Lista anterior){
    Lista atual= l;
    while(atual != NULL){
        if(atual->num == x ){
            // l = atual->prox;
            // if (anterior != NULL)
            //     l->prox = anterior;

            // anterior->prox = NULL;
            if (anterior == NULL){
                l = atual->prox;
                return l;
            }else{
                l = anterior;
            //if (atual->prox != NULL)
                l->prox = atual->prox;
            free(atual);
            return l;
            }
        }else{
            anterior = atual;
            atual= atual->prox;
            remover(atual, x, anterior);
            return l;
        }
    }

    return l;

}

int main(){

    Lista l = cria_lista();
    printf("Digite quantos numeros quer adicionar numa lista \n");

    int n, num;

    scanf("%d", &n);

    printf("Digite os numeros \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        l = add(l, num);

    }

    printf("Agora digite um numero para remover da lista \n");
    int x;
    scanf("%d", &x);

    l = remover(l, x, NULL);

    if (l == NULL){
        printf("Lista vazia \n");
    }else{
        
        printf("Nova lista:  \n");
        impressao(l);

        free(l->prox);
        free(l);
    }

    return 0;
}