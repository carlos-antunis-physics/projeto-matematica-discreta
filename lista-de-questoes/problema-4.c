/*
    Problema 4
        Escrever um programa para determinar o mdc e o mmc de dois inteiros com base em seus fatores primos.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

int main() {
    long long int A, B;
    printf("Digite dois números inteiros >= 1: ");
    scanf("%lld %lld", &A, &B);

    if (A <= 1 || B <= 1) {
        printf("Números devem ser >= 1.\n");
        return 1;
    }

    long long int a = A, b = B;
    long long int mdc = 1, mmc = 1;
    long long int p = 2;

    while (a > 1 || b > 1) {
        int contA = 0, contB = 0;

        while (a % p == 0) {
            contA++;
            a /= p;
        }
        while (b % p == 0) {
            contB++;
            b /= p;
        }

        int menor = contA < contB ? contA : contB;
        int maior = contA > contB ? contA : contB;

        for (int i = 0; i < menor; i++) mdc *= p;
        for (int i = 0; i < maior; i++) mmc *= p;

        p++;
      
        if (a == 1 && b == 1) break;
    }

    printf("MDC: %lld\n", mdc);
    printf("MMC: %lld\n", mmc);
    return 0;
}
