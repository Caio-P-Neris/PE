#include <stdio.h>

typedef struct {
    int lista[100]; // Assumindo que cada conjunto pode conter até 100 elementos.
    int tamanho;     // O tamanho atual do conjunto.
} Conjunto;

Conjunto conjunto_uniao(Conjunto con_a, Conjunto con_b) {
    Conjunto unido;
    int i, j;

    // Copie os elementos do primeiro conjunto (con_a) para o conjunto unido.
    for (i = 0; i < con_a.tamanho; i++) {
        unido.lista[i] = con_a.lista[i];
    }
    unido.tamanho = con_a.tamanho;

    // Verifique os elementos do segundo conjunto (con_b) e adicione-os ao conjunto unido se não estiverem presentes.
    for (j = 0; j < con_b.tamanho; j++) {
        int elemento = con_b.lista[j];
        int elementoJaPresente = 0;

        for (i = 0; i < unido.tamanho; i++) {
            if (unido.lista[i] == elemento) {
                elementoJaPresente = 1;
                break;
            }
        }

        if (!elementoJaPresente) {
            unido.lista[unido.tamanho] = elemento;
            unido.tamanho++;
        }
    }

    return unido;
}

int main() {
    Conjunto conjuntoA = {{1, 2, 3, 4, 5}, 5};
    Conjunto conjuntoB = {{3, 4, 5, 6, 7}, 5};
    Conjunto conjuntoUniao = conjunto_uniao(conjuntoA, conjuntoB);

    printf("Conjunto União: {");
    for (int i = 0; i < conjuntoUniao.tamanho; i++) {
        printf("%d", conjuntoUniao.lista[i]);
        if (i < conjuntoUniao.tamanho - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}