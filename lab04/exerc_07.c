// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *concatena( char *a, char *b){

    int tamanho_a = strlen(a);
    int tamanho_b = strlen(b);

    int tamanho_total = tamanho_a + tamanho_b +2; //mais dois para ter espaço em branco entre as strings e '/0' no fim

    char *r = (char *)malloc(tamanho_total);

    for (int i = 0; i < tamanho_a -1 ; i++){ 
        r[i] = a[i];
        //printf("%c\n", r[i]);
    }

    r[tamanho_a - 1] = ' '; // -1 pois é onde ficava o \n

    int j = 0;

    for (int i = tamanho_a ; i < tamanho_total ; i++){
        r[i] = b[j];
        //printf("%c\n", r[i]);

        j += 1;
    }

    return r;

}

int main(){

    char *a = NULL, *b = NULL, *resultado = NULL;
    size_t sizea = 0, sizeb = 0;

    printf("Digite a string A :\n");

    getline(&a, &sizea, stdin);

    //printf("%s", a);

    printf("Digite a string B: \n");

    getline(&b, &sizeb, stdin);

    //printf("%s", b); 

    resultado = concatena(a,b);

    printf("concatenado fica: \n");
    printf("%s\n", resultado);

    free(a);
    free(b);
    free(resultado);

    return 0;
}