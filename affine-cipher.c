
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i, x, result;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key a: ");
    scanf("%d", &a);

    printf("Enter key b: ");
    scanf("%d", &b);

    if (a < 0 || a >= 26 || b < 0 || b >= 26) {
        printf("Keys must be between 0 and 25.\n");
        return 1;
    }

    int gcd = 0;
    for (i = 1; i <= 26; i++) {
        if (a % i == 0 && 26 % i == 0)
            gcd = i;
    }

    if (gcd != 1) {
        printf("Invalid key a. Choose a relatively prime to 26.\n");
        return 1;
    }

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            x = toupper((unsigned char)text[i]) - 'A';
            result = (a * x + b) % 26;
            printf("%c", result + 'A');
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}