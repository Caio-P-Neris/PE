// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista* Lista;

struct lista{
    int num;
    Lista prox;
};

Lista cria(){
    return NULL;
}

Lista add(Lista l, int x){
    Lista novo = malloc(sizeof(struct lista));
    novo->num = x;
    novo->prox = l;

    return novo;
}

void imprime(Lista l){
    while (l != NULL){
        printf("%d \n ", l->num);
        l = l->prox;
    }
    
}

Lista concatena(Lista l1, Lista l2){
    Lista atual = l1;
    while(atual->prox!= NULL){
        atual = atual->prox;
    }

    atual->prox = l2;
    return l1; 
}

int main(){

    Lista l1 = cria();

    int n,m, x;
    printf("Digite a quantidade a ser inserida l1 \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        l1 = add(l1, x);
    }

    Lista l2 = cria();
    printf("Digite a quantidade a ser inserida l2 \n");
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        l2 = add(l2, x);
    }

    Lista lf = concatena(l1, l2);

    imprime(lf);
    //imprime(l1);
    //imprime(l2);

    return 0;
}