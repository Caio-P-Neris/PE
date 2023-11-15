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
    } else {
        VectorInt v_novo = vectorint();
        v_novo->capacity = (2 * v->capacity); 
        v_novo->nelements = v->nelements;
        v_novo->data = malloc(v_novo->capacity * sizeof(void*));

        // Copiar os ponteiros diretamente
        for (int i = 0; i < v->nelements; i++) {
            v_novo->data[i] = v->data[i];
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

void verifica(VectorInt v, void* a, int comando_tipo) {
    int verificador = 0;

    if (comando_tipo == 6) {
        int a_int = *((int*)a);
        for (int i = 0; i < v->nelements; i++) {
            int* elemento_vetor = (int*)v->data[i];  // Convertendo para o tipo correto
            if (*elemento_vetor == a_int) {
                verificador += 1;
                v->data[i] = (void*)elemento_vetor;  // Convertendo de volta para void*
            }
        }
    } else if (comando_tipo == 7) {
        char a_char = *((char*)a);
        for (int i = 0; i < v->nelements; i++) {
            char* elemento_vetor = (char*)v->data[i];  // Convertendo para o tipo correto
            if (*elemento_vetor == a_char) {
                verificador += 1;
                v->data[i] = (void*)elemento_vetor;  // Convertendo de volta para void*
            }
        }
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

void vectorint_remove(VectorInt v, void* a, int comando_tipo) {
    int count = 0;  // Contador para ocorrências do elemento a remover

    // Verifica o tipo de dados
    switch (comando_tipo) {
        case 6: {
            int a_int = *((int*)a);

            for (int i = 0; i < v->nelements; i++) {
                int* elemento_vetor = (int*)v->data[i];

                if (*elemento_vetor == a_int) {
                    count++;
                    free(elemento_vetor);
                } else {
                    // Se não for o elemento a ser removido, copia para o novo vetor
                    v->data[i - count] = v->data[i];
                }
            }
            break;
        }
        case 7: {
            char a_char = *((char*)a);

            for (int i = 0; i < v->nelements; i++) {
                char* elemento_vetor = (char*)v->data[i];

                if (*elemento_vetor == a_char) {
                    count++;
                    free(elemento_vetor);
                } else {
                    // Se não for o elemento a ser removido, copia para o novo vetor
                    v->data[i - count] = v->data[i];
                }
            }
            break;
        }
        // Adicione mais casos conforme necessário para outros tipos
        default:
            printf("Tipo de comando desconhecido.\n");
            return;
    }

    // Atualiza o número de elementos após a remoção
    v->nelements -= count;

    // Se o número de elementos é inferior a 1/4 da capacidade, reduza a capacidade pela metade
    if (v->nelements < (v->capacity / 2)) {
        v->capacity /= 2;
        v->data = realloc(v->data, v->capacity * sizeof(void*));
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
    printf("Digite o que deseja fazer agora\n");
    scanf("%d", &comando);

if (comando == 1) {

    printf("Digite o tipo do que vai adicionar. 6-> int, 7-> char, 8-> string\n");
    scanf("%d", &comando_tipo);

    printf("Digite o que deseja adicionar\n");

    if (comando_tipo == 6) {
        int* a_int = malloc(sizeof(int));
        scanf("%d", a_int);
        a = (void*)a_int;
    } else if (comando_tipo == 7) {
        char* a_char = malloc(sizeof(char));
        scanf(" %c", a_char);  // Adicionado espaço antes de %c para ignorar espaços em branco
        a = (void*)a_char;
    } else if (comando_tipo == 8) { // arrumar string
        printf("Digite a string: \n");
        char* a_str = malloc((m + 1) * sizeof(char));
        fgets(a_str, m + 1, stdin);  // m + 1 para incluir o caractere de nova linha
        a = (void*)a_str;
    }

    vectorint_insert(v, a);

} else if (comando == 2) {
    printf("Digite o tipo do que vai tirar. 6-> int, 7-> char, 8-> string\n");
    scanf("%d", &comando_tipo);

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

    vectorint_remove(v, a, comando_tipo);

} else if (comando == 3) {
    printf("Digite o tipo do que quer descobrir. 6-> int, 7-> char, 8-> string\n");
    scanf("%d", &comando_tipo);

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

    verifica(v, a, comando_tipo);

} else if (comando == 4) {
    printf("Digite a posicao, se encontrar, vai imprimir o que esta nela\n");
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

    free(v);
    free(a);


    return 0;
}
