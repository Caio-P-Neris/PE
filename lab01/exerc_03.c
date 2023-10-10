// Caio Pereira Neris, RA: 11202230288
#include <stdio.h>

void celsius_para_f(int c){
    double f;
    f = (c*9)/5.0 + 32;
    printf("%f\n", f);
}

void f_para_celsius(int f){
    double c;
    c = ((f - 32)*5)/9.0;
    printf("%f\n", c);
}

int main(){
    int t;
    char u;
    printf("Qual a unidade? (f para fahrenheit /c para celsius) ");
    u = getchar();
    printf("Valor: ");
    scanf("%d", &t);

    if (u == 'c'){
        celsius_para_f(t);
    } else if (u == 'f'){
        f_para_celsius(t);
    }


    return 0;
}