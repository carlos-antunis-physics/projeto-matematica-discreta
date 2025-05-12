/*
 * RSA encryption project back-end
 *
 * Created on: 08 - 05 - 2025
 *
 * Authors:
 *   Carlos, Filipe, Flavia, Giovanna and Mirian.
 *
 * Description:
 *   This code implements RSA encryption and decryption using GNU Multiple Precision
 *   Arithmetic Library (GMP). It includes functions to encrypt and decrypt messages,
 *   as well as to generate RSA keys. The code is designed to educational purposes -
 *   do not use it in production.
 *
 * Copyright (C) 2025 Carlos, Filipe, Flavia, Giovanna and Mirian
 */

//  Standard C libraries
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//  Emscripten libraries
#include <emscripten.h>

//  GNU Multiple Precision Arithmetic Library
#include "../gmp-6.3.0/mini-gmp/mini-gmp.c"

#define MAX_SIZE 70

bool __isPrime(mpz_t n)
{
    /*
    *   bool __isPrime(mpz_t)
    *       tests wether a number is prime or not.
    *
    *   @param mpz_t n: number to be tested
    */

    //  checks if n is not greater than 1
    if (mpz_cmp_ui(n, 1) <= 0)
    {
        return false;                               // for all prime number p: p > 1
    }

    mpz_t d, sqrt_n, r;

    mpz_init(d);
    mpz_init(sqrt_n);
    mpz_init(r);

    //  for bigger numbers, try to find a divisor between 2 and sqrt(n)
    mpz_sqrt(sqrt_n, n);                            // sqrt_n = sqrt(n)
    for (mpz_set_ui(d, 2); mpz_cmp(d, sqrt_n) <= 0; mpz_add_ui(d, d, 1))
    {
        mpz_mod(r, n, d);                           // r = n % d
        //  if r == 0, then d is a divisor of n
        if (mpz_cmp_ui(r, 0) == 0)
        {
            mpz_clear(d);
            mpz_clear(sqrt_n);
            mpz_clear(r);

            return false;                           // divisible, so it's not a prime
        }
    }

    mpz_clear(d);
    mpz_clear(sqrt_n);
    mpz_clear(r);

    return true;                                    //  otherwise, n is prime
}

EMSCRIPTEN_KEEPALIVE
const char *generatePublicKey(const char *_p, const char *_q, const char *_e)
{
    /*
    *   const char * generatePublicKey(const char *, const char *, const char *)
    *       Generates a public key using the RSA protocol.
    *
    *   @param const char * _p, q: prime numbers
    *   @param const char * _e: public exponent
    */

    mpz_t p, q, e;
    
    mpz_init(p);
    mpz_init(q);
    mpz_init(e);

    mpz_set_str(p, _p, 10);                         // p = _p
    mpz_set_str(q, _q, 10);                         // q = _q
    mpz_set_str(e, _e, 10);                         // e = _e

    //  check if p and q are prime numbers
    bool isPrimeP = __isPrime(p);
    bool isPrimeQ = __isPrime(q);

    if (!isPrimeP && !isPrimeQ)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);

        return "KEY_ERROR: ambos os primos invalidos";
    }
    else if (!isPrimeP)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);

        return "KEY_ERROR: primeiro primo invalido";
    }
    else if (!isPrimeQ)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);

        return "KEY_ERROR: primeiro primo invalido";
    }

    //  check if e is coprime with the Euler's totient function
    mpz_t n;
    
    mpz_init(n);
    mpz_mul(n, p, q);                               // n = pq
    
    if (mpz_cmp_ui(n, 126) < 0)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);
        mpz_clear(n);
        
        return "KEY_ERROR: o produto dos primos deve ser maior que 126 para ser reversivel";
    }
    
    
    mpz_t eulerTotient, gcd;
    
    mpz_init(eulerTotient);
    mpz_init(gcd);

    //  eulerTotient = (p - 1)(q - 1) = pq - p - q + 1 = n - p - q + 1
    mpz_sub(eulerTotient, n, p);
    mpz_sub(eulerTotient, eulerTotient, q);
    mpz_add_ui(eulerTotient, eulerTotient, 1);

    mpz_gcd(gcd, e, eulerTotient);                  // gcd = mdc(e, eulerTotient)
    mpz_clear(eulerTotient);
    //  if gcd(e, eulerTotient) != 1, then e is not coprime with Euler's totient function
    if (mpz_cmp_ui(gcd, 1) != 0)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);
        mpz_clear(n);
        mpz_clear(gcd);

        return "KEY_ERROR: e não é coprimo com (p - 1)(q - 1)";
    }
    mpz_clear(gcd);

    char *public_key = (char *)malloc(MAX_SIZE * sizeof(char));
    if (!public_key)
    {
        mpz_clear(p);
        mpz_clear(q);
        mpz_clear(e);
        mpz_clear(n);
        return "KEY_ERROR: falha ao alocar memória";
    }

    sprintf(public_key, "%s", mpz_get_str(NULL, 10, n));

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(e);
    mpz_clear(n);

    return public_key;
}

EMSCRIPTEN_KEEPALIVE
const char *encryptMessage(const char *_msg, const char *_n, const char *_e)
{
    /*
    *   const char * encryptMessage(const char *, const char *, const char *)
    *       Encrypts a message using RSA protocol for the informed public key.
    *
    *   @param const char * _msg: message to be encrypted
    *   @param const char * _n: public key modular base
    *   @param const char * _e: public exponent
    */

    mpz_t n, e;
    mpz_t m, c;

    mpz_init(n);
    mpz_init(e);
    mpz_init(m);
    mpz_init(c);

    mpz_set_str(n, _n, 10);                         // n = _n
    mpz_set_str(e, _e, 10);                         // e = _e

    size_t len = strlen(_msg);                      // len = length of msg
    char *cypher_text = (char *)malloc(len * (MAX_SIZE) * sizeof(char));
    if (!cypher_text)
    {
        mpz_clear(n);
        mpz_clear(e);
        mpz_clear(m);
        mpz_clear(c);
    
        return "KEY_ERROR: falha ao alocar memória";
    }
    cypher_text[0] = '\0';                          // initialize cypher_text

    //  Encrypt message char by char
    for (size_t i = 0; i < len; i++)
    {
        mpz_set_ui(m, (unsigned int)_msg[i]);       // m = (unsigned int)msg[i]
        mpz_powm(c, m, e, n);                       // c = m^e mod n
        strcat(cypher_text, mpz_get_str(NULL, 10, c));
        strcat(cypher_text, " ");
    }

    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(m);
    mpz_clear(c);

    return cypher_text;
}

EMSCRIPTEN_KEEPALIVE
const char *decryptMessage(char *_cphr, const char *_p, const char *_q, const char *_e)
{
    /*
    *   const char * decryptMessage(char *, const char *, const char *, const char *)
    *       Decrypts a message using RSA protocol for the informed private key.
    *
    *   @param char * _cphr: cypher text to be decrypted
    *   @param const char * _p, q: prime numbers
    *   @param const char * _e: public exponent
    */

    size_t lenMsg = 0;
    {
        size_t i = 0;
        while (_cphr[i] != '\0')
        {
            if (_cphr[i] == ' ')
                lenMsg++;
            i++;
        }
    }

    //  Get decryption key
    mpz_t n, d;
    mpz_t p, q, e, eulerTotient;

    mpz_init(p);
    mpz_init(q);
    mpz_init(e);
    mpz_init(n);
    mpz_init(d);
    mpz_init(eulerTotient);

    mpz_set_str(p, _p, 10);                         // p = _p
    mpz_set_str(q, _q, 10);                         // q = _q
    
    mpz_set_str(e, _e, 10);                         // e = _e
    
    mpz_mul(n, p, q);                               // n = pq
    
    //  eulerTotient = (p - 1)(q - 1) = pq - p - q + 1 = n - p - q + 1
    mpz_sub(eulerTotient, n, p);
    mpz_sub(eulerTotient, eulerTotient, q);
    mpz_add_ui(eulerTotient, eulerTotient, 1);

    mpz_invert(d, e, eulerTotient);                  // d = e^(-1) mod (p - 1)(q - 1)

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(e);
    mpz_clear(eulerTotient);

    char *message = (char *)malloc((lenMsg + 1) * sizeof(char));
    if (!message)
    {
        mpz_clear(n);
        mpz_clear(d);
        return "KEY_ERROR: falha ao alocar memória";
    }
    message[0] = '\0';                            // initialize message

    char *_c = (char *)malloc(MAX_SIZE);
    if (!_c)
    {
        mpz_clear(n);
        mpz_clear(d);
        free(message);
        return "KEY_ERROR: falha ao alocar memória";
    }
    mpz_t c, m;

    mpz_init(c);
    mpz_init(m);

    //  Decrypt message char by char
    for (size_t i = 0; i < lenMsg; i++)
    {
        sscanf(_cphr, "%s ", _c);
        _cphr += strlen(_c) + 1;
        mpz_set_str(c, _c, 10);                      // c = _cphr[i]
        mpz_powm(m, c, d, n);                        // m = c^d mod n
        strcat(message, (char [2]){(char)mpz_get_ui(m), '\0'});
    }

    free(_c);
    mpz_clear(n);
    mpz_clear(d);
    mpz_clear(c);
    mpz_clear(m);

    return message;
}