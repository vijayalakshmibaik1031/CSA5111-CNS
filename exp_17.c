#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock input, output;

    char text[9];

    printf("Enter 8-character ciphertext: ");
    scanf("%8s", text);

    printf("Enter 8-character key: ");
    scanf("%8s", (char *)key);

    DES_set_key_unchecked(&key, &schedule);

    memcpy(input, text, 8);

    // DES decryption
    DES_ecb_encrypt(&input, &output, &schedule, DES_DECRYPT);

    printf("Decrypted text: ");
    for(int i = 0; i < 8; i++)
        printf("%c", output[i]);

    printf("\n");

    return 0;
}