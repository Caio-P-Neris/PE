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

void impressao(Lista l){
    if (l != NULL){
        printf("%d \n", l->num);
        impressao(l->prox);
    }
}

Lista remover(Lista l, int x){
    Lista atual = l;
    Lista anterior = NULL;

    while (atual != NULL){
        if (atual->num == x && anterior == NULL){
            l = atual->prox;
            free(atual);
            return l;

        }else if (atual->num == x && atual->prox != NULL){
            
            anterior->prox = atual->prox;
            free(atual);

            return l;

        }else if(atual->num == x){
            anterior->prox = NULL;
            free(atual);
            return l;
        }else{
            anterior = atual;            
            atual = atual->prox;
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
    // l = add(l, 1); l = add(l, 10); l = add(l, 4); l = add(l, 2);
    // impressao(l);

    printf("Agora digite um numero para remover da lista \n");
    int x;
    scanf("%d", &x);

    l = remover(l, x);


    printf("Nova lista:  \n");
    impressao(l);

    free(l->prox);
    free(l);

    return 0;
}