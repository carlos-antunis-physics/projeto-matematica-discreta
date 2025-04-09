/*
    Problema 10
        Generalize o programa da questão anterior para funcionar com n congruências ao
        invés de somente 3, onde n será dado pelo usuário.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>
#include <stdlib.h>

long long int euclides_extendido(long long int, long long int, long long int *, long long int *);
static inline long long unsigned mdc(long long unsigned, long long unsigned);
short sao_coprimos(long long unsigned [], unsigned);
long long int inverso_modular(long long int, long long int);

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
        scanf("%llu mod %llu", &a[i], &b[i]);
    }
    if (sao_coprimos(b, N)) {
        //  imprimir o resultado da aplicacao do algoritmo derivado do teorema chines dos restos
        algoritmo_chines_para_restos(a, b, N);
        return 0;                       // finaliza a execucao
    }
    printf("[ERRO] os valores de b nao sao coprimos\n");
    return 0;                           // finaliza a execucao
}

inline long long unsigned mdc(long long unsigned a, long long unsigned b) {
    return (b == 0) ? a : mdc(b, a % b);
}

short sao_coprimos(long long unsigned numeros[], unsigned n) {
    short mdc_eh_1 = 1;
    for (int i = 0; i < n; i++) {       // para todos os pares
        for (int j = 0; j < i; j++) {   // de numeros distintos
            mdc_eh_1 = mdc_eh_1 && (mdc(numeros[i], numeros[j]) == 1);
        }
    }
    return mdc_eh_1;
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

long long int inverso_modular(long long int a, long long int b) {
    long long int x, y;
<<<<<<< HEAD
    long long int _ = euclides_estendido(a, b, &x, &y);
    return x % b;
=======
    long long int _ = euclides_extendido(a, b, &x, &y);
    long long int inv = x % b;
    return (inv < 0) ? inv + b : inv;
>>>>>>> 20a4604 (Minor fixes (fix broken dependencies and typos))
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

    printf("a solucao eh congruente a %llu mod %llu\n", soma_total % mul_total, mul_total);
    return;
}