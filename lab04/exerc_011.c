// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int* data;
int capacity; 
int nelements; 
} VectorInt;


VectorInt vectorint(){

    VectorInt *v = malloc(sizeof(VectorInt));
    if (v){
    v->data = malloc(sizeof(int));
    v->capacity = 1;
    v->nelements = 0;
    }

    return *v;
}

void vectorint_insert(VectorInt v, int a){
    if (v.nelements < v.capacity){
        v.data[v.nelements] = a;
        v.nelements += 1;
    }else{
        
    }



    // printf("%d em %d -1 \n", a, v.nelements);
    // printf("%d\n", v.data[0]);

}

int main(){

    int a, i;

    VectorInt v = vectorint();
    int comando = 0;



    printf("Voce pode escolher a funcao que deseja fazer por comandos\n");

    printf("Para inserir um numero no vetor, digite 1. Para remover todas ocorrencias de um numero do vetor, digite 2\n");
    printf("Para saber se um numero pertence ao vetor, digite 3, para retornar um elemento da iesima posicao, digite 4\n");
    printf("Para saber a quantidade atual de elementos no vetor, digite 5, para encerrar o programa e liberar a memória, digite -1\n");


    while (comando != -1){
        scanf("%d", &comando);

        if (comando == 1){
            printf("Digite o numero que deseja adicionar\n");
            scanf("%d", &a);
            vectorint_insert(v, a);
        }

    

    
    
    }
    

    return 0;
}