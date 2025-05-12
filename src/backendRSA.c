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

bool __isPrime(mpz_t n) {
    /*
    *   bool __isPrime(mpz_t)
    *       Checks if a number is prime or not.
    *   
    *   @param mpz_t n: number to be checked
    */

    //  checks if n is less or equals to 1
    if (mpz_cmp_ui(n, 1) <= 0)
    {
        //  which is not prime numbers
        return false;
    }
    mpz_t d, square_root_n, remainder;

    mpz_init(d);
    mpz_init(square_root_n);
    mpz_init(remainder);

    mpz_sqrt(square_root_n, n);                     // square_root_n = sqrt(n)
    
    //  for bigger numbers, try to find a divisor from 2 to sqrt(n)
    for (mpz_set_ui(d, 2); mpz_cmp(d, square_root_n) <= 0; mpz_add_ui(d, d, 1)) {
        mpz_mod(remainder, n, d);                   // remainder = n % d
        if (mpz_cmp_ui(remainder, 0) == 0) {

            mpz_clear(d);
            mpz_clear(square_root_n);
            mpz_clear(remainder);

            return false;                           // divisible, so it's not a prime
        }
    }

    mpz_clear(d);
    mpz_clear(square_root_n);
    mpz_clear(remainder);

    return true; // not divisible, so it's a prime
}

EMSCRIPTEN_KEEPALIVE
char *generatePublicKey(const char *_p, const char *_q, const char *_e) {
    /*
    *   char * generatePublicKey(const char *, const char *, const char *)
    *       Generates the public key for RSA encryption in "public_key.txt" file
    *       if its possible, returning the resulting error code.
    * 
    *   @param const char * _p: first prime number
    *   @param const char * _q: second prime number
    *   @param const char * _e: public exponent
    */

    mpz_t p, q, e;

    mpz_set_str(p, _p, 10);                          // p = _p
    mpz_set_str(q, _q, 10);                          // q = _q
    mpz_set_str(e, _e, 10);                          // e = _e

    //  check if p and q are prime numbers
    if (!__isPrime(p) || !__isPrime(q)) {
        return "KEY_ERROR_INVALID_PRIMES";
    }
    mpz_t n, mult, gcd;

    mpz_init(n);
    mpz_init(mult);
    mpz_init(gcd);

    mpz_mul(n, p, q);                               // n = p * q
    
    mpz_sub(mult, n, p);                            // mult = pq - p
    mpz_sub(mult, mult, q);                         // mult = pq - p - q
    mpz_add_ui(mult, mult, 1);                      // mult = pq - p - q + 1 = (p - 1)(q - 1)

    mpz_gcd(gcd, e, mult);                          // gcd = mdc(e, mult)
    if (mpz_cmp_ui(gcd, 1) != 0) {
        // e is not coprime to (p - 1)(q - 1)
        mpz_clear(n);
        mpz_clear(mult);
        mpz_clear(gcd);
        return "KEY_ERROR_INVALID_E";
    }
    
    char *public_key = mpz_get_str(NULL, 10, n);

    mpz_clear(n);
    mpz_clear(mult);
    mpz_clear(gcd);

    return public_key;
}

EMSCRIPTEN_KEEPALIVE
char *encryptMessage(char *msg, const char *_n, const char *_e)
{
    /*
    *   char * encryptMessage(char *, const char *, const char *)
    *       Encrypts a message using RSA protocol for the informed public key in
    *       "cypher.txt" file.
    *
    *   @param char *msg: message to be encrypted
    *   @param const char * _n: public key modular base
    *   @param const char * _e: public exponent
    */

    mpz_t n, e;
    mpz_t m, c;
    
    mpz_set_str(n, _n, 10);                         // n = _n
    mpz_set_str(e, _e, 10);                         // e = _e

    mpz_init(m);
    mpz_init(c);

    size_t N = strlen(msg);                         // N = length of msg
    char *cypher_text = (char *)malloc(N * (mpz_sizeinbase(n, 10) + 1) * sizeof(char));
    cypher_text[0] = '\0';                          // initialize cypher_text

    //  Encrypt message char by char
    for (size_t i = 0; i < N; i++)
    {
        mpz_set_ui(m, (unsigned char)msg[i]);       // m = (unsigned)msg[i]
        mpz_powm(c, m, e, n);                       // c = m^e mod n
        strcat(cypher_text, mpz_get_str(NULL, 10, c));
        strcat(cypher_text, " ");
    }
    
    mpz_clear(m);
    mpz_clear(c);

    return cypher_text;
}

EMSCRIPTEN_KEEPALIVE
char *decryptMessage(char *_cphr, const char *_p, const char *_q, const char *_e)
{
    /*
    *   char *decryptMessage(char *, const char *, const char *, const char *)
    *       Decrypts a message using RSA protocol for the informed private key in
    *       "message.txt" file.
    * 
    *   @param char *_cphr: cyphertext to be decrypted
    *   @param const char * _p: first prime number
    *   @param const char * _q: second prime number
    *   @param const char * _e: public exponent
    */
   
    //  Get private key
    mpz_t n, d;
    mpz_t m, mult;

    size_t len = 0, i = 0;

    while (_cphr[i] != '\0')
    {
        if (_cphr[i] == ' ') len++;
        i++;
    }

    mpz_t cphr[len], p, q, e;
    
    mpz_set_str(p, _p, 10);                         // p = _p
    mpz_set_str(q, _q, 10);                         // q = _q
    mpz_set_str(e, _e, 10);                         // e = _e
    
    mpz_init(n);
    mpz_mul(n, p, q);                               // n = p * q
    
    char *message = (char *)malloc((len + 1) * sizeof(char));
    char *c = (char *)malloc(mpz_sizeinbase(n, 10) + 1);
    
    message[0] = '\0';                            // initialize message
    
    for (size_t i = 0; i < len; i++)
    {
        mpz_init(cphr[i]);
        sscanf(_cphr, "%s ", c);
        _cphr += strlen(c) + 1;
        mpz_set_str(cphr[i], c, 10);                // cphr[i] = _cphr[i]
    }

    mpz_init(m);
    mpz_init(d);
    mpz_init(mult);

    mpz_sub(mult, n, p);                            // mult = n - p
    mpz_sub(mult, mult, q);                         // mult = n - p - q
    mpz_add_ui(mult, mult, 1);                      // mult = n - p - q + 1 = (p - 1)(q - 1)
    
    mpz_invert(d, e, mult);                         // d = inv{e} mod (p - 1)(q - 1)
    
    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(e);
    mpz_clear(mult);

    //  Decrypt message char by char
    for (size_t i = 0; i < len; i++)
    {
        mpz_powm(m, cphr[i], d, n); // m = c^d mod n
        strcat(message, (char [2]){(char)mpz_get_ui(m), '\0'});
    }
    
    mpz_clear(m);
    mpz_clear(n);
    mpz_clear(d);

    return message;
}