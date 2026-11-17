
#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key1 = "12345678";
    DES_cblock key2 = "abcdefgh";
    DES_cblock key3 = "87654321";

    DES_key_schedule ks1, ks2, ks3;

    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_cblock iv = "12345678";

    unsigned char data[16] = "HELLO CBC MODE";
    unsigned char output[16];

    DES_ede3_cbc_encrypt(
        data, output, 16,
        &ks1, &ks2, &ks3,
        &iv, DES_ENCRYPT
    );

    printf("Encrypted Ciphertext:\n");

    for(int i = 0; i < 16; i++)
        printf("%02X ", output[i]);

    printf("\n");

    return 0;
}
