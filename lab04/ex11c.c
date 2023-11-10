// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector {
    int* data;
    int capacity; 
    int nelements; 
};

typedef struct vector* VectorInt;

VectorInt vectorint(){

    VectorInt v = malloc(sizeof(struct vector));
    if (v){
    //v->capacity = 0;
    v->data = malloc(sizeof(int));
    v->capacity = 1;
    v->nelements = 0;
    }

    return v;
}

void vectorint_insert(VectorInt v, int a){
    if (v->nelements < v->capacity){
        v->data[v->nelements] = a;
        v->nelements += 1;
    }else{
        VectorInt v_novo = vectorint();
        v_novo->capacity = (2*v->capacity);  //declara que a nova capacidade é o dobro da capacidade antiga
        v_novo->nelements = v->nelements;
        for (int i =0; i < v->nelements; i++){
            v_novo->data[i] = v->data[i]; // copia toda 'data' do antigo pro novo
            v_novo->nelements += 1; 
        }
        v_novo->data[v->nelements] = a; //ao fim do vetor data, adiocina o inteiro a digitado
        v_novo->nelements += 1; 

        free(v->data);
        *v = *v_novo;

    }



    // printf("%d em %d -1 \n", a, v->nelements);
    // printf("%d\n", v->data[0]);

}

void verifica(VectorInt v, int a){
    int verificador = 0;
    for(int i = 0; i < v->nelements; i++){
        if (v->data[i] == a)
            verificador += 1;
    }

    if (verificador == 0)
        printf("nao esta presente \n");
    else
        printf("esta presente \n");

}

int procura(VectorInt v, int i){
    int numero = -1;
    if (v->capacity-1 >= i){
        numero = v->data[i];
    }

    return numero;

}

int main(){
    int a, i;

    VectorInt v = vectorint();
    int comando = 0;



    printf("Voce pode escolher a funcao que deseja fazer por comandos\n");

    printf("Para inserir um numero no vetor, digite 1. Para remover todas ocorrencias de um numero do vetor, digite 2\n");
    printf("Para saber se um numero pertence ao vetor, digite 3, para retornar um elemento da iesima posicao, digite 4\n");
    printf("Para saber a quantidade atual de elementos no vetor, digite 5, para encerrar o programa e liberar a memoria, digite -1\n");


    while (comando != -1){
        printf("\n");
        printf("Digite um comando\n");

        scanf("%d", &comando);

        if (comando == 1){
            printf("Digite o numero que deseja adicionar\n");
            scanf("%d", &a);
            vectorint_insert(v, a);
        } else if (comando == 3){
            printf("Digite o numero que voce quer descobrir se pertence ao vetor: \n");
            scanf("%d", &a);
            verifica(v, a);
        } else if (comando == 4){
            printf("Digite a posicao, se retornar -1 e porque nao existe essa posicao, se encontrar, vai imprimir o numero\n");
            scanf("%d", &i);
            int pos = procura(v,i);
            printf("%d\n", pos);
        }

    

    
    
    }


    return 0;
}
