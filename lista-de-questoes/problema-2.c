/*
    Problema 2
        Escrever um programa para listar números primos sequencialmente. Você deve
        otimizar o programa para que ele liste o maior número possível de primos em
        60 segundos.
    
    Autores: Carlos, Filipe, Flavia, Giovanna, Mírian
*/

#include <stdio.h>
#include <time.h>

short eh_primo(long long unsigned);
void imprimir_primos();

int main() {
    //  requisita a impressão dos primos
    imprimir_primos();
    return 0;                           // finaliza a execucao sem erros
}

short eh_primo(long long unsigned n) {
    const short False = 0, True = 1;
    for (int i = 2; i * i <= n; i++) {  // para todos os possiveis divisores
        //  caso o resto da divisao entre n e o divisor seja 0
        if (!(n % i)) {
            return False;               // o numero eh composto
        }
    }
    //  caso nenhum dos possiveis divisores o divida
    return True;                        // o numero eh primo
}

void imprimir_primos() {
    time_t inicio, agora;
    unsigned long long contador = 0u;
    long long unsigned n = 2;           // inicia pelo primeiro numero primo
    //  requisita o valor do tempo no inicio da execucao
    time(&inicio);
    do {
        if (eh_primo(n)) {              // sendo primo, imprima o numero
            contador++;
<<<<<<< HEAD
            printf(“%llu eh o %llu\n” numero primo!”, n, contador);
=======
            printf("%llu eh o %llu numero primo!\n", n, contador);
>>>>>>> 20a4604 (Minor fixes (fix broken dependencies and typos))
        }
        //  requsite o processamento do proximo numero
        n++;
        //  obtenha o tempo de agora
        time(&agora);
    } while (difftime(agora, inicio) <= 60);
    return;                             // retorne ao programa principal
}
