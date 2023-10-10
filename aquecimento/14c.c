#include <stdio.h>

int main() {
    int n, temp, digito, inverso = 0, acc = 1;
    scanf("%d", &n);
    
    temp = n; // Faça uma cópia de n para não alterar o valor original

    // Inverte o número
    while (temp > 0) {
        digito = temp % 10;
        inverso = inverso * 10 + digito;
        temp /= 10;
    }

    // Compara os dígitos do número original com o número invertido
    while (n > 0) {
        digito = n % 10;
        int digitoInverso = inverso % 10;

        if (digito != digitoInverso) {
            acc = 0; // Se encontrarmos dígitos diferentes, definimos acc para 0
            break;   // Saímos do loop, pois não é mais necessário verificar
        }

        n /= 10;
        inverso /= 10;
    }

    if (acc == 1) {
        printf("sim");
    } else {
        printf("nao");
    }

    return 0;
}