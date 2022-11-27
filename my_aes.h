/*
 * aes.h
 *
 *  Created on: 27 Nov 2022
 *      Author: irfan.karazor
 */

#ifndef AES_H_
#define AES_H_


#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <openssl/aes.h>


extern char* encryptJson(char *value);

/* AES key for Encryption and Decryption */
const static unsigned char aes_key[]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};

#endif /* AES_H_ */
