// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _aluno {
    int ra;
    char nome[1000];
    char sexo;
    int idade;
};

typedef struct _aluno* Aluno;

char aluno_cmp(Aluno a, Aluno b){

    if (a->ra == b->ra &&
        strcmp(a->nome, b->nome) == 0 &&
        a->sexo == b->sexo &&
        a->idade == b->idade) {
        return '1';
    } else
        return '0';

}

Aluno cadastro(){
    Aluno x = malloc(sizeof(struct _aluno));

    printf("Qual o nome? \n");

    fgets(x->nome, sizeof(x->nome), stdin); 

    //printf("%s\n", x->nome);

    printf("Qual o RA? \n");

    scanf("%d", &x->ra);

    //printf("%d\n", x->ra);

    getchar();

    printf("Qual o sexo? (M ou F) \n");

    x->sexo = getchar();

    //printf("%c\n", x->sexo);

    printf("Qual a idade? \n");

    scanf("%d", &x->idade);

    //printf("%d\n", x->idade);

    getchar();

    return x;
}

int main(){

    printf("Vamos pegar os dados do primeiro aluno (a) \n");
    Aluno a = cadastro(); 

    printf("Vamos pegar os dados do segudndo aluno (b) \n");
    Aluno b = cadastro();

    char resp = aluno_cmp(a,b);

    printf("Se retornar 1 o conteudo apontado por um aluno e o mesmo que o outro, se retornar 0 e diferente \n");

    printf("%c\n", resp);

    free(a);
    free(b);
    return 0;
}