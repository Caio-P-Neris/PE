// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include "conjunto.h"
#define MAX 100

Conjunto conjunto(int vet[MAX], int tamanho){
    int i;
    Conjunto con;
    con.tamanho = tamanho;
    for (i = 0; i < con.tamanho; i++)
        con.lista[i] = vet[i];

    return con;
}

Conjunto conjunto_uniao(Conjunto con_a, Conjunto con_b){
    Conjunto unido;
    int i, j;
    for (i = 0; i < con_a.tamanho; i++){
        unido.lista[i] = con_a.lista[i];
    }

    unido.tamanho = con_a.tamanho;

    for (j = 0; j < con_b.tamanho; j++) {
        int elemento = con_b.lista[j];
        int elemento_presente = 0;

        for (i = 0; i < unido.tamanho; i++) {
            if (unido.lista[i] == elemento) {
                elemento_presente = 1;
                break;
            }
        }

        if (elemento_presente == 0) {
            unido.lista[unido.tamanho] = elemento;
            unido.tamanho++;
        }
    }
   return unido;
}

void le_conjunto(Conjunto con){
    int i;
    for (i =0; i < con.tamanho; i++){
        printf("%d  ", con.lista[i]);
    }
}

int conjunto_pertence(int a, Conjunto con_a){
    int acc = 0;
    for (int i = 0; i < con_a.tamanho; i++){
        if (a == con_a.lista[i]){
            acc = 1;
        }
    }
    return acc;
}