#include <stdio.h>

void comb(int n, int *vetor, int tamanho) {
    if (n == 0) {
        for (int i = tamanho - 1; i >= 0; i--) { // percorre de tras pra frente para fazer sentido
            printf("%d", vetor[i]);
        }
        printf("\n");
    } else {
        vetor[tamanho] = n;
        comb(n - 1, vetor, tamanho + 1);
        comb(n - 1, vetor, tamanho);
    }
}

int main() {
    int n;

    printf("Digite o n: ");
    scanf("%d", &n);

    int vetor[n];

    comb(n, vetor, 0);

    return 0;
}