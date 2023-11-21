// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comb(int n, int k, int* vetor, int ini, int fim, int indic, int* vfinal){

    if(k == indic){
        for(int i = 0; i < k; i++){ 
            printf("%d ", vfinal[i]);
        }
        printf("\n");

    } else{
        for(int i = ini; i <= fim && fim -i +1 >= k - indic; i++ ){  
        //for(int i = ini; i <= fim; i++ ){  //arrumar aqui! ta errado
            vfinal[indic] = vetor[i];
            comb(n, k, vetor, i +1, fim, indic +1, vfinal);
        }
    }
}

int main(){

    int n, k;

    printf("Digite n e k nessa ordem \n");
    scanf("%d %d", &n, &k);

    int* vetor = malloc(n*sizeof(int));
    printf("Digite cada digito \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    int* vfinal = malloc(k*sizeof(int));

    comb(n, k, vetor, 0, n -1, 0, vfinal);

    free(vetor);
    free(vfinal);

    return 0;
}