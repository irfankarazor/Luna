/*
 * aes.c
 *
 *  Created on: 27 Nov 2022
 *      Author: irfan.karazor
 */


#include <openssl/aes.h>

#include "my_aes.h"


/* Print Encrypted and Decrypted data packets */
void print_data(const char *tittle, const void* data, int len);
unsigned char *result;
char* encryptJson(char *value)
{
    /* Input data to encrypt */

    unsigned char aes_input[strlen(value)];//={0x0,0x1,0x2,0x3,0x4,0x5};
    strncpy(aes_input,value,strlen(value));
    //printf("aes json %s",aes_input);
    /* Init vector */
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    /* Buffers for Encryption and Decryption */
    unsigned char enc_out[sizeof(aes_input)];
    unsigned char dec_out[sizeof(aes_input)];

    /* AES-128 bit CBC Encryption */
    AES_KEY enc_key,dec_key;
    AES_set_encrypt_key(aes_key, sizeof(aes_key)*8, &enc_key);
    AES_cbc_encrypt(aes_input, enc_out, sizeof(aes_input), &enc_key, iv, AES_ENCRYPT);

    /* AES-128 bit CBC Decryption */
    memset(iv, 0x00, AES_BLOCK_SIZE); // don't forget to set iv vector again, else you can't decrypt data properly
    AES_set_decrypt_key(aes_key, sizeof(aes_key)*8, &dec_key); // Size of key is in bits
    AES_cbc_encrypt(enc_out, dec_out, sizeof(aes_input), &dec_key, iv, AES_DECRYPT);

    /* Printing and Verifying */
    //print_data("\n Original ",aes_input, sizeof(aes_input)); // you can not print data as a string, because after Encryption its not ASCII

    print_data("\n Encrypted",enc_out, sizeof(enc_out));
    print_data("\n Decrypted",dec_out, sizeof(dec_out));
    printf("\nDecrypted as text : %s\n\n",dec_out);

    int len = sizeof(enc_out);
    result = (unsigned char *)malloc(len*(sizeof(char)));
    strncpy(result,enc_out,len);

    return result;
}

void print_data(const char *tittle, const void* data, int len)
{
    printf("%s : ",tittle);
    const unsigned char * p = (const unsigned char*)data;
    int i = 0;
    printf("\npdata len %d\n",len);
    for (; i<len; ++i)
        printf("%02X ", *p++);

    printf("\n");
}
