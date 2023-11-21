// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// numero total : 2^n -1
// n = 2    n = 3        n = 4
//  1          1            1
//  2          2            2
//  12         3            3
//              12          4
//              13          12
//              23          13
//              123         14
                        //  23
                        //  24
                        //  34 
                        //  123
                        //  124
                        //  134
                        //  234
                        //  1234
                        


void comb(int n, int* vetor, int tamanho){
//void comb(int n){
    //int original = n;

    if (n == 0) {
        for (int i = tamanho - 1; i >= 0; i--) { // agr vem de tras pra frente
            printf("%d", vetor[i]);
        }
        printf("\n");
    }else{
        //vetores[i] = (int*)malloc(tamanho * sizeof(int));

        vetor[tamanho] = n;
        comb(n - 1, vetor, tamanho + 1);
        comb(n - 1, vetor, tamanho);
        }

}

int main(){
    int n;

    printf("Digite o n \n");
    scanf("%d", &n);

    int vetor[n];

    //int n_combinacoes = (int)(pow(2, n) +0.5) -1;
    //int** vetores = (int**)malloc(n_combinacoes * sizeof(int*));
    
    comb(n, vetor, 0);
    return 0;
}