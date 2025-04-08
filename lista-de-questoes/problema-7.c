/*
    Problema 7
        Escrever um programa para encontrar o inverso de a mod b.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

long long int inverso_modular(long long int, long long int);

int main() {
    long long int a, b;
    //  requisite a leitura de a mod b
    printf("insira a mod b: ");
    scanf("%lld mod %lld", &a, &b);
    if (sao_coprimos(b)) {
        //  imprima o inverso modular de a mod b
        printf("o inverso modular de %lld mod %lld eh %lld\n", a, b, inverso_modular(a, b));
        return 0;                       // finaliza a execucao
    }
    printf("[ERRO] os valores de b nao sao coprimos\n");
    return 0;                           // finaliza a execucao sem erros
}

long long int inverso_modular(long long int a, long long int b) {
    const short True = 1;
    int inv = 1;
    while (True) {                      // enquanto o inverso modular nao for encontrado
        if ((a * inv) % b == 1) {       // teste se inv eh o inverso modular
            return inv;
        }
        //  teste o proximo
        inv++;
    }
}