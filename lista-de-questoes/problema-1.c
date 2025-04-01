/*
    Problema 1
        Escrever um programa que determina se um dado número inteiro é primo ou não.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

short eh_primo(long long int);

int main() {
    long long int n;
    //  efetuar a leitura do numero
    scanf("%lld", &n);
    //  imprimir se o numero eh primo
    printf("o numero %lld%s eh primo\n", n, (eh_primo(n)) ? "" : " nao");
    return 0;                           // finaliza a execucao sem erros
}

short eh_primo(long long int n) {
    const short False = 0, True = 1;
    for (int i = 2; i * i <= n; i++) {  // para todos os possiveis divisores
        //  caso o resto da divisao entre n e o divisor seja 0
        if (!(n % i)) {
            return False;               // o numero eh composto
        }
    }
    //  caso nenhum dos possiveis divisores o divida
    return True;                        // o numero eh primo
}