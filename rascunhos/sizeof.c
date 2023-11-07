#include <stdio.h>

void swap(int *a, int *b, size_t tamanho_a, size_t tamanho_b) {
    size_t tamanho_menor = tamanho_a < tamanho_b ? tamanho_a : tamanho_b;
    
    for (size_t i = 0; i < tamanho_menor; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {6, 7, 8, 9, 10};
    size_t tamanho_a = sizeof(a) / sizeof(a[0]);
    size_t tamanho_b = sizeof(b) / sizeof(b[0]);

    printf("Antes da troca:\n");
    for (size_t i = 0; i < tamanho_a; i++) {
        printf("a[%zu] = %d, b[%zu] = %d\n", i, a[i], i, b[i]);
    }

    swap(a, b, tamanho_a, tamanho_b);

    printf("Depois da troca:\n");
    for (size_t i = 0; i < tamanho_a; i++) {
        printf("a[%zu] = %d, b[%zu] = %d\n", i, a[i], i, b[i]);
    }

    return 0;
}