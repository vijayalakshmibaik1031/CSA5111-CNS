#include <stdio.h>
int main() {
    char word[100];
    int shift, i;

    printf("Enter a word: ");
    if (scanf("%99s", word) != 1) {
        return 1;
    }

    printf("Enter the shift value (positive or negative): ");
    if (scanf("%d", &shift) != 1) {
        return 1;
    }
    shift = ((shift % 26) + 26) % 26;

    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = (word[i] - 'A' + shift) % 26 + 'A';
        }
        else if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = (word[i] - 'a' + shift) % 26 + 'a';
        }
    }

    printf("Encrypted word: %s\n", word);

    return 0;
}