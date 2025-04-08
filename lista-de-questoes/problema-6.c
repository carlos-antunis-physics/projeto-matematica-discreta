/*
    Problema 6
        Escrever um programa para encontrar os coeficientes s e t da combinação linear mdc(a, b) = s · a + t · b.

    Autores: Carlos, Filipe, Flavia, Giovanna, Mirian
*/

#include <stdio.h>
#include <stdlib.h>

long long mdc_estendido(long long a, long long b, long long *s, long long *t) {
    long long s0 = 1, s1 = 0; //coeficientes iniciais de 'a'
    long long t0 = 1, t1 = 0; //coeficientes iniciais de 'b'
    long long q, temp;

    while (b != 0) {
        q = a / b; //coeficiente da divisão

        //essa parte vai atualizar 'a' e 'b' - algoritmo de euclides
        temp = b; //(esse temp é váriavel temporária) aqui ela guarda o valor antigo de 'b' em temp
        b = a % b; //atualiza 'b' para o resto da divisão
        a = temp; //restaura o valor antigo de 'b' em 'a'

        //atualiza o s e t
        temp = s1;
        s1 = s0 - q * s1;
        s0 = temp;

        temp = t1;
        t1 = t0 - q * t1;
        t0 = temp;
    }

    *s = s0;
    *t = t0;
    return a; //mdc(a, b)
}

int main() {
    
    long long a, b, s, t, resultado;

    printf("Digite 'a' e 'b': ");
    scanf("%lld %lld", &a, &b);
    
    resultado = mdc_estendido(a, b, &s, &t);
        
    printf("\nMDC(%lld, %lld) = %lld\n", a, b, resultado);
    printf("Coeficientes: s = %lld, t = %lld\n", s, t);
    printf("Combinação linear: %lld*%lld + %lld*%lld = %lld\n", s, a, t, b, s*a + t*b);

    return 0;
}