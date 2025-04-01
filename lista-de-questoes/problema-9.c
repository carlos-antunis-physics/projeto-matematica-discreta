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
short sao_coprimos(long long unsigned []);
long long unsigned inverso_modular(long long unsigned, long long unsigned);

void algoritmo_chines_para_restos(long long unsigned [], long long unsigned [], unsigned);

int main() {
    long long unsigned a[3], b[3];
    //  requerer a leitura das congruencias
    printf("insira a primeira congruencia (a mod b): ");
    scanf("%lld mod %lld", &a[0], &b[0]);
    printf("insira a segunda congruencia (a mod b): ");
    scanf("%lld mod %lld", &a[1], &b[1]);
    printf("insira a terceira congruencia (a mod b): ");
    scanf("%lld mod %lld", &a[2], &b[2]);
    if (sao_coprimos(b)) {
        //  imprimir o resultado da aplicacao do algoritmo derivado do teorema chines dos restos
        algoritmo_chines_para_restos(a, b, 3);
        return 0;                       // finaliza a execucao
    }
    printf("[ERRO] os valores de b nao sao coprimos\n");
    return 0;                           // finaliza a execucao
}

inline long long unsigned mdc(long long unsigned a, long long unsigned b) {
    return (b == 0) ? a : mdc(b, a % b);
}

short sao_coprimos(long long unsigned numeros[]) {
    return mdc(numeros[2], mdc(numeros[1], numeros[0])) == 1;
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