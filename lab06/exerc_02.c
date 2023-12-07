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

Lista procura(Lista l, int x){

    if(l == NULL){
        //printf("Nao esta presente \n");
        return NULL;
    } else if(l->num == x){
        //printf("esta presente \n");
        return l;
    } else{
        procura(l->prox, x);
        //printf("%p\n", temp);
        //return NULL;
        }
    //return  NULL;
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
    //impressao(l);

    printf("Agora digite um numero para saber se esta na lista \n");
    int x;
    scanf("%d", &x);

    Lista resp = procura(l, x);

    if ( resp != NULL)
        printf("ponteiro : %p\n", resp);
    else
        printf("NULL \n");


    free(resp->prox);
    free(resp);
    free(l->prox);
    free(l);
    return 0;
} // perguntar do valgrind quando n tem o numero