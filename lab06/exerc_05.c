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

int conta_aparicoes(Lista l, int x){
    int contador = 0;
    Lista atual = l;
    while(atual != NULL){
        if(atual->num == x)
            contador +=1;
        atual = atual->prox;
    }

    return contador;
}

Lista remover(Lista l, int x, Lista anterior, int contador){
    Lista atual= l;
    while(atual != NULL){
        if(atual->num == x ){
            // l = atual->prox;
            // if (anterior != NULL)
            //     l->prox = anterior;

            // anterior->prox = NULL;
            if (anterior == NULL){
                l = atual->prox;
                contador -=1;
                free(atual);
                if(contador == 0)
                    return l;
                else
                    return remover(l, x, anterior, contador);
            }else{
                l = anterior;
            //if (atual->prox != NULL)
                l->prox = atual->prox;
                free(atual);
                contador -= 1;
                remover(l, x, anterior, contador);
                return l;
            }
        }else{
            anterior = atual;
            atual= atual->prox;
            remover(atual, x, anterior, contador);
            return l;
        }
    }

    return l;

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
        l = add(l, num);

    }

    printf("Agora digite um numero para remover da lista \n");
    int x;
    scanf("%d", &x);

    int contador = conta_aparicoes(l, x);

    //printf("contador : %d\n", contador);

    l = remover(l, x, NULL, contador);

    if (l == NULL){
        printf("Lista vazia \n");
    }else{
        
        printf("Nova lista:  \n");
        impressao(l);

        // free(l->prox);
        // free(l);
    }

    l = destroir_lista(l);

    

    return 0;
}