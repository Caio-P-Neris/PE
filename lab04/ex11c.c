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
            //v_novo->nelements += 1; 
        }
        v_novo->data[v->nelements] = a; //ao fim do vetor data, adiocina o inteiro a digitado
        v_novo->nelements += 1; 

        free(v->data);
        *v = *v_novo;
        free(v_novo);


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
    //if (v->capacity-1 >= i){
    if (v->nelements > i){
        numero = v->data[i];
    }

    return numero;

}

int conta(VectorInt v){
    int n_element = v->nelements;

    return n_element;
}

void vectorint_remove(VectorInt v, int a){
//     for (int i = 0; i < v->nelements; i++){
//         if(v->data[i] == a){
//    desolocou         for(int j = i; j < v->nelements; j++){
//                 v->data[j] = v->data[j+1];

//             }
//         v->nelements -= 1;
//         }
//     } //isso daqui ñ tava funcionando pra remover mais de um pq se fizer i +=1 sempre, acaba deixando sem verificar uma parte pq é deslocado

    int i = 0;
    //int j = 0;

    while (i < v->nelements) {
        if (v->data[i] == a) {
            // Encontrou, ñ muda i para procurar outros depois que deslocar tudo pra esquerda
            //v->nelements -= 1;  

            for (int j = i; j < v->nelements-1 ; j++) {
                v->data[j] = v->data[j + 1];
            }

            v->nelements -= 1;  
            // if (i != 0)
            //     i--;
        } else {
            i++;  // muda i só se ñ achou a no data[i]
        }
    }

    if (v->nelements < (v->capacity/2)){
        
        v->capacity = v->capacity/2;
        VectorInt v_novo = vectorint();
        v_novo->capacity = v->capacity;
        v_novo->nelements = v->nelements;

        for (int i = 0; i < v_novo->nelements; i++){
            v_novo->data[i] = v->data[i];
        }

        free(v->data);
        *v = *v_novo;
    }

}

void limpa_memoria(VectorInt v){
    free(v->data);

    free(v);
}

int main(){
    int a, i;

    VectorInt v = vectorint();
    int comando = 0;

    printf("Voce pode escolher a funcao que deseja fazer por comandos\n");

    printf("Para inserir um numero no vetor, digite 1. Para remover todas ocorrencias de um numero do vetor, digite 2\n");
    printf("Para saber se um numero pertence ao vetor, digite 3, para retornar um elemento da iesima posicao, digite 4\n");
    printf("Para saber a quantidade atual de elementos no vetor, digite 5, para encerrar o programa e liberar a memoria, digite -1\n");


    while (comando != -2){
        printf("\n");
        printf("Digite um comando\n");

        scanf("%d", &comando);

        if (comando == 1){
            printf("Digite o numero que deseja adicionar\n");
            scanf("%d", &a);
            vectorint_insert(v, a);

        } else if(comando == 2){ 
            printf("Digite o elemento que quer remover todas ocorrencias: \n");
            scanf("%d", &a);
            vectorint_remove(v, a);

        }else if (comando == 3){
            printf("Digite o numero que voce quer descobrir se pertence ao vetor: \n");
            scanf("%d", &a);
            verifica(v, a);

        } else if (comando == 4){
            printf("Digite a posicao, se retornar -1 e porque nao existe essa posicao, se encontrar, vai imprimir o numero\n");
            scanf("%d", &i);
            int pos = procura(v,i);
            printf("%d \n", pos);

        } else if (comando ==5){
            int n_element = conta(v);
            printf("quantidade atual de elementos: %d\n", n_element);
        } else if (comando == -1){
            printf("A memoria total foi liberada e o programa vai encerrar \n");
            limpa_memoria(v);
            comando = -2;
        }
    
    }

    free(v);
    return 0;
}
