// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector {
    void** data;
    int capacity; 
    int nelements; 
};

typedef struct vector* VectorInt;

VectorInt vectorint(void){

    VectorInt v = malloc(sizeof(struct vector));
    if (v){

    v->data = malloc(sizeof(int));
    v->capacity = 1;
    v->nelements = 0;
    }

    return v;
}

void vectorint_insert(VectorInt v, void* a){
    if (v->nelements < v->capacity){
        v->data[v->nelements] = a;
        v->nelements += 1;
    }else{
        VectorInt v_novo = vectorint();
        v_novo->capacity = (2*v->capacity); 
        v_novo->nelements = v->nelements;
        for (int i =0; i < v->nelements; i++){
            v_novo->data[i] = v->data[i]; 
            //v_novo->nelements += 1; 
        }
        v_novo->data[v->nelements] = a; 
        v_novo->nelements += 1; 

        free(v->data);
        *v = *v_novo;
        free(v_novo);

    }
    // printf("%d em %d -1 \n", a, v->nelements);
    // printf("%d\n", v->data[0]);

}

void verifica(VectorInt v, void* a){
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

void* procura(VectorInt v, int i) {
    void* elemento = NULL;

    // Verifica se a posição i é válida no vetor
    if (i >= 0 && i < v->nelements) {
        elemento = v->data[i];
    }

    return elemento;
}

int conta(VectorInt v){
    int n_element = v->nelements;

    return n_element;
}

void vectorint_remove(VectorInt v, void* a){
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

// int cria_int(){
//     int* a = malloc(sizeof(int));
    
//     return a;
// }

int main(){
    void *a;
    int i;

    VectorInt v = vectorint();
    int comando = 0;

    printf("Digite 6 para que seu proximo dado seja do tipo int, 7 para que seja char ou 8 para que seja string\n");
    printf("\n");
    printf("Para inserir, digite 1. Para remover todas ocorrencias, digite 2\n");
    printf("Para saber se pertence ao vetor, digite 3, para retornar da iesima posicao, digite 4\n");
    printf("Para saber a quantidade atual de elementos, digite 5, para encerrar o programa e liberar a memoria, digite -1\n");
    printf("\n");

    int m, comando_tipo;

    while (comando != -2){
        printf("Digite o comando que explicite qual o tipo do dado a ser inserido / analisado \n");

        scanf("%d", &comando_tipo);

        if (comando_tipo == 6){
            int* a_int = malloc(sizeof(int));
            scanf("%d", a_int);
            a = (void*)a_int;

        } else if (comando_tipo == 7){
            char* a_char = malloc(sizeof(char));
            scanf(" %c", a_char);  
            a = (void*)a_char;
            
        } else if(comando_tipo == 8){
            printf("Qual tamanho dessa string? \n");
            scanf("%d", &m);
            char* a_str = malloc((m + 1) * sizeof(char));
            scanf("%s", a_str);
            a = (void*)a_str;
        }
        
        printf("Digite o que deseja fazer agora\n");
        scanf("%d", &comando);

if (comando == 1) {
    printf("Digite o que deseja adicionar\n");

    if (comando_tipo == 6) {
        int* a_int = malloc(sizeof(int));
        scanf("%d", a_int);
        a = (void*)a_int;
    } else if (comando_tipo == 7) {
        char* a_char = malloc(sizeof(char));
        scanf(" %c", a_char);  // Adicionado espaço antes de %c para ignorar espaços em branco
        a = (void*)a_char;
    } else if (comando_tipo == 8) {
        printf("Digite a string: \n");
        char* a_str = malloc((m + 1) * sizeof(char));
        fgets(a_str, m + 1, stdin);  // m + 1 para incluir o caractere de nova linha
        a = (void*)a_str;
    }

    vectorint_insert(v, a);

} else if (comando == 2) {
    printf("Digite o elemento que quer remover todas ocorrencias: \n");

    if (comando_tipo == 6) {
        int a_int;
        scanf("%d", &a_int);
        a = (void*)&a_int;
    } else if (comando_tipo == 7) {
        char a_char;
        scanf(" %c", &a_char);
        a = (void*)&a_char;
    } else if (comando_tipo == 8) {
        printf("Digite a string: \n");
        char a_str[m + 1];
        fgets(a_str, m + 1, stdin);
        a = (void*)a_str;
    }

    vectorint_remove(v, a);

} else if (comando == 3) {
    printf("Digite o que voce quer descobrir se pertence ao vetor: \n");

    if (comando_tipo == 6) {
        int a_int;
        scanf("%d", &a_int);
        a = (void*)&a_int;
    } else if (comando_tipo == 7) {
        char a_char;
        scanf(" %c", &a_char);
        a = (void*)&a_char;
    } else if (comando_tipo == 8) {
        printf("Digite a string: \n");
        char a_str[m + 1];
        fgets(a_str, m + 1, stdin);
        a = (void*)a_str;
    }

    verifica(v, a);

        } else if (comando == 4) {
            printf("Digite a posicao, se retornar NULL e porque nao existe essa posicao, se encontrar, vai imprimir o que esta nela\n");
            scanf("%d", &i);
            
            void* resultado = procura(v, i);

            if (resultado != NULL) {

                if (comando_tipo == 6) {
                    printf("%d\n", *((int*)resultado));
                } else if (comando_tipo== 7) {
                    printf("%c\n", *((char*)resultado));
                } else if (comando_tipo == 8) {
                    printf("%s\n", (char*)resultado);
                }
            } else {
                printf("Posicao nao existe no vetor.\n");
            }

        } else if (comando ==5){
            int n_element = conta(v);
            printf("quantidade atual de elementos: %d\n", n_element);
        } else if (comando == -1){
            printf("A memoria total foi liberada e o programa vai encerrar \n");
            limpa_memoria(v);
            comando = -2;
        } 
    
    }


    return 0;
}
