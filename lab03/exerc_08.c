// Caio Pereira Neris RA: 11202230288
#include <stdio.h>
#include <string.h>
#define MAX 100

struct data{
    int dia;
    int mes;
    int ano;
};

typedef struct data Data;

struct aluno{
    char nome[MAX];
    char sobrenome[MAX];
    long long int ra;
    Data nascimento;

};

typedef struct aluno Aluno;

Aluno cadastro(){
    Aluno alun;
    char nome[MAX];
    int  size_nome, i;

    printf("Vamos cadastras alunos \n");
    printf("Digite o nome com sobrenome \n");
    getchar();
    fgets(nome, MAX, stdin);
    
    size_nome = strlen(nome);

   if (size_nome > 0 && nome[size_nome-1 ] == '\n'){
    nome[size_nome - 1] = '\0';
   }

    for (i = 0; i < size_nome; i++){
        // if(nome[i] != ' '){
            alun.nome[i] = nome[i];
            // alun.nome[i] = '\0';
        // }else{

        // }    
    }


    printf("Qual a data de nascimento? Digite so o dia:  \n");
    scanf("%d", &alun.nascimento.dia);
    printf("Digite o mes \n");
    scanf("%d", &alun.nascimento.mes);
    printf("Digite o ano \n");
    scanf("%d", &alun.nascimento.ano);

    printf("Digite o RA \n");
    scanf("%lld", &alun.ra);  // meu ra para apenas int já dava problema, achei melhor deixar long long int 

    return alun;

}
void imprime_dados(Aluno alun){
    printf("Nome completo e %s\n", alun.nome);

    printf("Data de nascimento %d / %d / %d \n", alun.nascimento.dia, alun.nascimento.mes, alun.nascimento.ano );
    printf("Ra: %lld\n", alun.ra);
}

void busca_nome(int i, Aluno alunos[MAX]){
    Aluno alun;
    char nome[MAX];
    int size_nome, j;

    printf("Qual o nome ou sobrenome do aluno? \n");
    getchar();
    fgets(nome, MAX, stdin);

    size_nome = strlen(nome);

   if (size_nome > 0 && nome[size_nome-1 ] == '\n'){
    nome[size_nome - 1] = '\0';
   }

    char lista_sepNomes[MAX], lista_sep_nome[MAX];

    for (j = 0; j < i; j++){
        for( int b = 0; alunos[j].nome[b] != ' '; b++){
            lista_sepNomes[b] = alunos[j].nome[b];

        }
        if (strcmp(lista_sepNomes[j], nome) == 0){
            strcpy(alun.nome, lista_sepNomes[j]);
            alun.ra = alunos[j].ra;
            alun.nascimento = alunos[j].nascimento;

            printf("Achei algo o seguinte alunos \n");
            imprime_dados(alun);
        }
    }

}

void busca_data(Aluno alunos[MAX], int i){
    Aluno alun;
    int ano, j;

    printf("Digite um ano, iremos listar os alunos no intervalo desse ano \n");
    scanf("%d", &ano);

    for (j =0; j < i; j++ ){
        alun = alunos[j];
        if (ano == alun.nascimento.ano){
            printf("Achamos o seguinte aluno: \n");
            imprime_dados(alun);
        }
    }

}


int main(){

    Aluno alun, alunos[MAX];
    int comando = 0, i = 0;

    while ( comando != -1){
        printf("Para cadastrar alunos, digite 1. Para buscar por nome ou sobrenome, digite 2. Para buscar alunos por data de nascimento, digite 3. Para sair digite -1\n");
        scanf("%d", &comando);

        if (comando == 1){
            alun = cadastro();
            alunos[i] = alun; 
        } else if (comando == 2){
            busca_nome(i, alunos);

        } else if( comando == 3){
            busca_data(alunos, i);
        }

        i += 1;

    }

    return 0;
}