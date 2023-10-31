#include <stdio.h>


int soma_linha(int matriz[100][100], int n){
    
    int somaslinhas[100];
    int slinha = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            slinha += matriz[i][j];
        }
        somaslinhas[i] = slinha; 
        slinha = 0;
    }

    int somascol[100];
    int scol = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scol += matriz[j][i];
        }
        somascol[i] = scol; 
        scol = 0;
    }

    int verificador = 0;
    int sentinela = somaslinhas[0]; 
    for(int i = 0; i < n; i++){
        if (somascol[i] != sentinela || somaslinhas[i] != sentinela){
            printf("Faltou magia");
            verificador = 1;
            break;
        }
    }

    return verificador;

}


int main(){

    int n, matriz[100][100], resultado;

    printf("Digite n\n");

    scanf("%d", &n);

    printf("vamo la\n");

    
    for(int i =0; i< n; i++){
        int j =0;
        scanf("%d %d %d", &matriz[i][j], &matriz[i][j+1], &matriz[i][j+2]);
    }

    resultado = soma_linha(matriz, n);
    // for(int i =0; i < n; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    if (resultado == 0){
        printf("magico");
    }


    return 0;
}
