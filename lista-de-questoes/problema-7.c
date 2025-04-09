/*
    Problema 7
        Escrever um programa para encontrar o inverso de a mod b.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

static inline long long unsigned mdc(long long unsigned, long long unsigned);
short sao_coprimos(long long unsigned, long long unsigned);
long long int inverso_modular(long long int, long long int);
long long int euclides_estendido(long long int, long long int, long long int*, long long int*);

int main() {
    long long int a, b;
    //  requisite a leitura de a mod b
    printf("insira a mod b: ");
    scanf("%lld mod %lld", &a, &b);
    if (sao_coprimos(a, b)) {
        //  imprima o inverso modular de a mod b
        printf("o inverso modular de %lld mod %lld eh %lld\n", a, b, inverso_modular(a, b));
        return 0;                       // finaliza a execucao
    }
    printf("[ERRO] os valores de b nao sao coprimos\n");
    return 0;                           // finaliza a execucao sem erros
}
inline long long unsigned mdc(long long unsigned a, long long unsigned b) {
    return (b == 0) ? a : mdc(b, a % b);
}

long long int euclides_extendido(long long int a, long long int b, long long int *x, long long int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long int x1, y1;
    long long int d = euclides_extendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return d;
}

short sao_coprimos(long long unsigned a, long long unsigned b) {
  return mdc(a, b) == 1;
}

long long int inverso_modular(long long int a, long long int b) {
    long long int x, y;
    long long int _ = euclides_extendido(a, b, &x, &y);
    long long int result = x % b;
    return (result < 0) ? result + b : result;
}