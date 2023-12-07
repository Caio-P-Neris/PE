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

Lista concatena(Lista l1, Lista l2) {
    Lista l3 = l1;

    if (l1 == NULL) 
        return l2;
    

    while (l3->prox != NULL) 
        l3 = l3->prox;
    

    l3->prox = l2;

    return l1;
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
    Lista l2 = cria_lista();
    printf("Digite quantos numeros quer adicionar na lista 1\n");

    int n, num, m;

    scanf("%d", &n);

    printf("Digite os numeros \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
            
            l1 = add(l1, num);

    }

    printf("Digite quantos numeros quer adicionar na lista 2\n");

    scanf("%d", &m);

    printf("Digite os numeros \n");

    for(int i = 0; i < m; i++){
        scanf("%d", &num);
            
            l2 = add(l2, num);

    }

    printf("Lista 2 concatenada no fim da Lista 1 fica:  \n");

    Lista l3 = concatena(l1, l2);

    impressao(l3);

    l3 = destroir_lista(l3);
    //l2 = destroir_lista(l2);
    //l1 = destroir_lista(l1);

    return 0;
}