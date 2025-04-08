/*
    Problema 8
        Escrever um programa para encontrar a solução de uma congruência do tipo ax ≡ b mod m.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/
#include <stdio.h>

// Função para calcular o MDC
int mdc(int num1, int num2){
    while(num2 != 0){
        int i = num1 % num2;
        num1 = num2;
        num2 = i;
    }
    return num1;
}

// Algoritmo de Euclides Estendido
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

// Função para resolver ax ≡ b mod m
long long int congruencia_linear(long long int a, long long int b, long long int m){
    long long int x0, y, d;

    // calcula o mdc de a e m
    d = mdc(a, m);

    // caso quando o mdc(a,m) nao divide b
    if (b % d != 0){
        printf("Não existe solução.\n");
        return -1;
    }

    euclides_extendido(a, m, &x0, &y);
    
    // solução particular (ajuste para valor positivo)
    x0 = ((x0 * (b / d)) % m + m) % m;

    // se há uma única solução
    if (d == 1){
        printf("Solução única: x ≡ %lld mod %lld\n", x0, m);
        return x0;
    }

    // exibe todas as d soluções
    printf("A congruência possui %lld soluções:\n", d);
    for (int k = 0; k < d; k++) {
        long long int solucao = (x0 + k * (m / d));
        solucao = (solucao % m + m) % m;
        printf("x ≡ %lld mod %lld\n", solucao, m);
    }

    return -1; // múltiplas soluções foram impressas
}

int main() {
    long long int a, b, m;

    printf("Insira ax ≡ b mod m: ");
    scanf("%lldx ≡ %lld mod %lld", &a, &b, &m);
    
    congruencia_linear(a, b, m);

    return 0;
}
