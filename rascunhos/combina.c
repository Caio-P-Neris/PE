#include <stdio.h>

// Função recursiva para imprimir combinações
void imprimirCombinacoesRecursivo(int n, int i, int currentCombination) {
    if(n == 1)
        printf("%d\n", n);

    else if (i > n) {
        //int j, k =1;
        for (int j = 0, k = 1; j < n; j++, k <<= 1) {
            if (currentCombination & k) {
                printf("%d ", j + 1);
            
            }
        }
        printf("\n");
        return;
    }

    // Chamar recursivamente para incluir ou não o próximo número na combinação
    imprimirCombinacoesRecursivo(n, i + 1, currentCombination | (1 << (i - 1)));
    imprimirCombinacoesRecursivo(n, i + 1, currentCombination);
}

// Função principal
int main() {
    int n;

    // Solicitar ao usuário um número positivo
    printf("Digite um numero positivo: ");
    scanf("%d", &n);



    // Chamar a função recursiva para imprimir as combinações
    imprimirCombinacoesRecursivo(n, 1, 0);

    return 0;
}
