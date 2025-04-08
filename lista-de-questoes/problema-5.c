/*
    Problema 5
        Escrever um programa para determinar o mdc de dois números com base no Algoritmo de Euclides.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

long long mdc(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    long long a, b;

    printf("Digite dois números para calcular o MDC:\n");
    scanf("%lld %lld", &a, &b);

    printf("MDC(%lld, %lld) = %lld\n", a, b, mdc(a, b));

    return 0;
}

