
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0, p, k, c;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%99s", key);

    int keyLen = strlen(key);

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            p = toupper((unsigned char)text[i]) - 'A';
            k = toupper((unsigned char)key[j % keyLen]) - 'A';

            c = (p + k) % 26;
            printf("%c", c + 'A');

            j++;
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}