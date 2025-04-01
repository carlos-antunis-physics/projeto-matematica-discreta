/*
    Problema 9
        Escrever um programa para encontrar a solução única de três congruências
        usando o Teorema Chinês do Resto. (Lembre-se de verificar se os módulos
        são coprimos).

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>
#include <stdlib.h>

static inline long long unsigned mdc(long long unsigned, long long unsigned);
long long unsigned mdc_recursivo(long long unsigned [], unsigned);
short sao_coprimos(long long unsigned [], unsigned);
long long unsigned inverso_modular(long long unsigned, long long unsigned);

void algoritmo_chines_para_restos(long long unsigned [], long long unsigned [], unsigned);

int main() {
    unsigned N;
    //  requerer a quantidade de equacoes
    printf("insira a quantidade de congurencias a serem lidas: ");
    scanf("%u", &N);
    long long unsigned a[N], b[N];
    for (int i = 0; i < N; i++) {       // para cada congruencia
        //  requerer a leitura das congruencias
        printf("insira a congruencia %d (a mod b): ", i + 1);
        scanf("%lld mod %lld", &a[i], &b[i]);
    }
    //  imprimir o resultado da aplicacao do algoritmo derivado do teorema chines dos restos
    algoritmo_chines_para_restos(a, b, N);

    return 0;                           // finaliza a execucao sem erros
}

inline long long unsigned mdc(long long unsigned a, long long unsigned b) {
    return (b == 0) ? a : mdc(b, a % b);
}
long long unsigned mdc_recursivo(long long unsigned numeros[], unsigned n) {
    if (n == 2) {                       // havendo apenas dois calcule o mdc
        return mdc(numeros[1], numeros[0]);
    }
    //  havendo mais aplique recursao
    return mdc(numeros[n - 1], mdc_recursivo(numeros, n - 1));
}

short sao_coprimos(long long unsigned numeros[], unsigned n) {
    return mdc_recursivo(numeros, n) == 1;
}

long long unsigned inverso_modular(long long unsigned a, long long unsigned b) {
    const short True = 1;
    unsigned inv = 1u;
    while (True) {                      // enquanto o inverso modular nao for encontrado
        if ((a * inv) % b == 1) {       // teste se inv eh o inverso modular
            return inv;
        }
        //  teste o proximo
        inv++;
    }
}

void algoritmo_chines_para_restos(long long unsigned a[], long long unsigned b[], unsigned N) {
    long long unsigned M[N];            // multiplicacao dos demais modulos
    long long unsigned INV[N];          // inverso modular da classe de equivalencia de M
    long long unsigned mul_total = 1;
    long long unsigned soma_total = 0;

    // para cada congruencia
    for (int i = 0; i < N; i++) {
        M[i] = 1;
        for (int j = 0; j < N; j++) {
            if (j == i) {               // exceto para i == j
                continue;
            }
            M[i] *= b[j];               // compute o produto de todos os modulos
        }
        INV[i] = inverso_modular(M[i] % b[i], b[i]);
        mul_total *= b[i];
        soma_total += a[i] * M[i] * INV[i];
    }

    printf("a solucao eh congruente a %lld mod %lld\n", soma_total % mul_total, mul_total);
    return;
}