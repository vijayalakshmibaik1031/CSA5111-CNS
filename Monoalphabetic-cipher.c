
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[27], cipher[27];
    int i, j, k = 0, used[26] = {0};

    printf("Enter the key word: ");
    scanf("%26s", key);

    // Generate substitution alphabet from key
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            cipher[k++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Append remaining unused letters
    for (i = 0; i < 26; i++) {
        if (!used[i])
            cipher[k++] = 'A' + i;
    }
    cipher[26] = '\0';

    printf("Enter the plaintext: ");
    getchar();
    fgets(text, sizeof(text), stdin);

    printf("Ciphertext: ");
    for (i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);

        if (ch >= 'A' && ch <= 'Z') {
            printf("%c", cipher[ch - 'A']);
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}