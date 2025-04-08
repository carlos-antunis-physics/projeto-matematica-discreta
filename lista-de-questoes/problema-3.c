/*
    Problema 3
        Escrever um programa para decompor um determinado número inteiro em seus fatores primos.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>

#define MAX_FATORES 100  // Tamanho máximo do array de fatores

int isPrimo(long long int b) { // a função da primeira questão
    if (b <= 1) return 0;
    for (int i = 2; i * i <= b; i++) {
        if (b % i == 0) return 0;
    }
    return 1;
}

// Fatora e preenche um array com os fatores primos
int fatorarEmPrimos(long long int n, long long int fatores[]) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        while (isPrimo(i) && n % i == 0) { //enquanto for primo e divisor de n, coloca no array e muda n
            fatores[count++] = i;
            n /= i;
        }
    }
    return count;  // Retorna a quantidade de fatores encontrados
}

int main() {
    long long int numero;
    long long int fatores[MAX_FATORES];
    long long int quantidade;

    printf("Digite um número inteiro maior que 1: ");
    scanf("%lld", &numero);

    if (numero <= 1) {
        printf("Número inválido. Deve ser maior que 1.\n");
        return 1;
    }

    quantidade = fatorarEmPrimos(numero, fatores);

    printf("Fatores primos de %lld: ", numero);
    for (int i = 0; i < quantidade; i++) {
        printf("%lld", fatores[i]);
        if (i < quantidade - 1) printf(" ");
    }
    printf("\n");
}