/*
    Problema 6
        Escrever um programa para encontrar os coeficientes s e t da combinação linear mdc(a, b) = s · a + t · b.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>
#include <stdlib.h>

long long mdc_estendido(long long a, long long b, long long *s, long long *t) {
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;  
    long long q, temp;

    while (b != 0) {
        q = a / b;

        temp = b;
        b = a % b;
        a = temp;

        temp = s1;
        s1 = s0 - q * s1;
        s0 = temp;

        temp = t1;
        t1 = t0 - q * t1;
        t0 = temp;
    }

    *s = s0;
    *t = t0;

    //garante que o MDC seja positivo
    if (a < 0) {
        a = -a;
        *s = -*s;
        *t = -*t;
    }

    return a;
}

int main() {
    long long a, b, s, t, resultado;

    printf("Digite 'a' e 'b': ");
    scanf("%lld %lld", &a, &b);

    if (a == 0 && b == 0) {
        printf("\nMDC(0, 0) é indefinido.\n");
        return 1;
    }

    resultado = mdc_estendido(a, b, &s, &t);

    printf("\nMDC(%lld, %lld) = %lld\n", a, b, resultado);
    printf("Coeficientes: s = %lld, t = %lld\n", s, t);
    printf("Combinação linear: %lld*%lld + %lld*%lld = %lld\n", s, a, t, b, s*a + t*b);

    return 0;
}
