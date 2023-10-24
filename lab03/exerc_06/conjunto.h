#ifndef CONJUNTO_H
#define CONJUNTO_H
#define MAX 100

struct conjunto
{
    int lista[MAX];
    int tamanho;
};

typedef struct conjunto Conjunto; 

Conjunto conjunto(int vet[MAX], int tamanho);

Conjunto conjunto_uniao(Conjunto con_a, Conjunto con_b);

char conjunto_pertence(int a, Conjunto con_a);

void le_conjunto(Conjunto con);

#endif