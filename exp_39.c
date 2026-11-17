
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c[500], p[500];
    int freq[26] = {0}, score[26];
    int i, j, shift, temp;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    for (i = 0; c[i]; i++)
        if (isalpha(c[i]))
            freq[toupper(c[i]) - 'A']++;

    int english[] = {
        8, 2, 3, 4, 13, 21, 34, 55, 89, 1,
        5, 13, 3, 7, 31, 2, 1, 26, 27, 35,
        10, 9, 1, 1, 2, 1
    };

    for (shift = 0; shift < 26; shift++) {
        score[shift] = 0;

        for (j = 0; j < 26; j++)
            score[shift] += freq[j] *
                english[(j - shift + 26) % 26];
    }

    printf("\nTop 10 possible plaintexts:\n");

    for (i = 0; i < 10; i++) {
        int best = -1, bestScore = -1;

        for (shift = 0; shift < 26; shift++) {
            if (score[shift] > bestScore) {
                bestScore = score[shift];
                best = shift;
            }
        }

        printf("\n%d. ", i + 1);

        for (j = 0; c[j]; j++) {
            if (isupper(c[j]))
                putchar((c[j] - 'A' - best + 26) % 26 + 'A');
            else if (islower(c[j]))
                putchar((c[j] - 'a' - best + 26) % 26 + 'a');
            else
                putchar(c[j]);
        }

        score[best] = -1;
    }

    return 0;
}
