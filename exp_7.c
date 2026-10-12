
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[] =
    "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;"
    "]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);"
    "5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;"
    "1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
    "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";

    char key[256];
    int i;

    for (i = 0; i < 256; i++)
        key[i] = '?';

    printf("Enter substitution mapping for ciphertext symbols.\n");
    printf("This basic version supports ASCII symbols only.\n");
    printf("Enter ciphertext symbol and plaintext letter, e.g. 6e\n");
    printf("Enter 0 to finish mapping.\n");

    while (1)
    {
        char symbol, plain;

        printf("Mapping: ");
        if (scanf(" %c", &symbol) != 1)
            break;

        if (symbol == '0')
            break;

        if (scanf(" %c", &plain) != 1)
            break;

        key[(unsigned char)symbol] = (char)tolower((unsigned char)plain);
    }

    printf("\nDecrypted message:\n");

    for (i = 0; cipher[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)cipher[i];

        if (key[c] != '?')
            putchar(key[c]);
        else
            putchar(cipher[i]);
    }

    printf("\n");
    return 0;
}
