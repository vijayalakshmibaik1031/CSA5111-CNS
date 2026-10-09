#include <stdio.h>

int main() {
    char text[500];
    int i, c, a = 3, b = 15, inv = 9;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            c = text[i] - 'A';
            text[i] = (inv * (c - b + 26)) % 26 + 'A';
        }
    }

    printf("Decrypted text: %s", text);
    return 0;
}