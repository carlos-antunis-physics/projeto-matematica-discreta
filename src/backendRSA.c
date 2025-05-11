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

//  GNU Multiple Precision Arithmetic Library
#include <gmp.h>

//  enumeration of error codes
typedef enum {
    KEY_VALID = 0,
    KEY_ERROR_INVALID_PRIMES,
    KEY_ERROR_INVALID_E,
} public_key_result_t;

bool isPrime(mpz_t n) {
    /*
    *   bool isPrime(mpz_t)
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

public_key_result_t generatePublicKey(mpz_t p, mpz_t q, mpz_t e) {
    /*
    *   public_key_result_t generatePublicKey(mpz_t, mpz_t, mpz_t)
    *       Generates the public key for RSA encryption in "public_key.txt" file
    *       if its possible, returning the resulting error code.
    * 
    *   @param mpz_t p: first prime number
    *   @param mpz_t q: second prime number
    *   @param mpz_t e: public exponent
    */

    //  check if p and q are prime numbers
    if (!isPrime(p) || !isPrime(q)) {
        return KEY_ERROR_INVALID_PRIMES;
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
        return KEY_ERROR_INVALID_E;
    }
    
    FILE *public_key_file = fopen("public_key.txt", "w");
    gmp_fprintf(public_key_file, "%Zd %Zd\n", n, e); // save public key to file

    mpz_clear(n);
    mpz_clear(mult);
    mpz_clear(gcd);
    fclose(public_key_file);

    return KEY_VALID; // public key was generated successfully
}

void encryptMessage(char *mnsg, mpz_t n, mpz_t e)
{
    /*
    *   void encryptMessage(char *, mpz_t, mpz_t)
    *       Encrypts a message using RSA protocol for the informed public key in
    *       "cypher.txt" file.
    *
    *   @param char *mnsg: message to be encrypted
    *   @param mpz_t n: public key modular base
    *   @param mpz_t e: public exponent
    */

    //  Open cyphertext file
    FILE *cypher_text = fopen("cypher.txt", "w");

    mpz_t m, c;

    mpz_init(m);
    mpz_init(c);

    //  Encrypt message char by char
    for (size_t i = 0; i < strlen(mnsg); i++)
    {
        mpz_set_ui(m, (unsigned char)mnsg[i]);      // m = (unsigned)mnsg[i]
        mpz_powm(c, m, e, n);                       // c = m^e mod n
        gmp_fprintf(cypher_text, "%Zd ", c);
    }
    
    mpz_clear(m);
    mpz_clear(c);

    fclose(cypher_text);
    return;
}

void decryptMessage(mpz_t *cphr, size_t len, mpz_t p, mpz_t q, mpz_t e)
{
    /*
    *   void decryptMessage(mpz_t *, size_t, mpz_t, mpz_t, mpz_t)
    *       Decrypts a message using RSA protocol for the informed private key in
    *       "message.txt" file.
    * 
    *   @param mpz_t *cphr: cyphertext to be decrypted
    *   @param size_t len: length of the cyphertext
    *   @param mpz_t p: first prime number
    *   @param mpz_t q: second prime number
    *   @param mpz_t e: public exponent
    */

    //  Open message file
    FILE *message = fopen("message.txt", "w");
   
    //  Get private key
    mpz_t n, d;
    mpz_t m, mult;

    mpz_init(m);
    mpz_init(n);
    mpz_init(d);
    mpz_init(mult);

    mpz_mul(n, p, q);                               // n = p * q
    
    mpz_sub(mult, n, p);                            // mult = n - p
    mpz_sub(mult, mult, q);                         // mult = n - p - q
    mpz_add_ui(mult, mult, 1);                      // mult = n - p - q + 1 = (p - 1)(q - 1)

    mpz_invert(d, e, mult);                         // d = inv{e} mod (p - 1)(q - 1)

    //  Decrypt message char by char
    for (size_t i = 0; i < len; i++)
    {
        mpz_powm(m, cphr[i], d, n);                 // m = c^d mod n
        fprintf(message, "%c", (char)mpz_get_ui(m));
    }

    mpz_clear(m);
    mpz_clear(n);
    mpz_clear(d);
    mpz_clear(mult);

    fclose(message);
    return;
}