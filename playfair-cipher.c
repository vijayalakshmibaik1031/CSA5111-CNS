
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[100], text[200], matrix[5][5];
    int used[26] = {0};
    int i, j, r, c, k = 0;
    char ch, a, b;
    int r1, c1, r2, c2;

    used['J' - 'A'] = 1;

    printf("Enter the key: ");
    scanf("%99s", key);

    printf("Enter the plaintext: ");
    scanf("%199s", text);

    // Generate 5x5 key matrix
    for (i = 0; i < (int)strlen(key); i++) {
        ch = toupper((unsigned char)key[i]);
        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }

    printf("\nKey Matrix:\n");
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++)
            printf("%c ", matrix[r][c]);
        printf("\n");
    }

    // Prepare plaintext
    char prepared[400];
    int n = 0;

    for (i = 0; text[i] != '\0'; i++) {
        ch = toupper((unsigned char)text[i]);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'J')
                ch = 'I';
            prepared[n++] = ch;
        }
    }

    prepared[n] = '\0';

    // Encrypt pairs, inserting X for repeated letters
    printf("\nCiphertext: ");

    for (i = 0; i < n; ) {
        a = prepared[i];
        b = (i + 1 < n) ? prepared[i + 1] : 'X';

        if (a == b) {
            b = 'X';
            i++;
        } else {
            i += 2;
        }

        r1 = c1 = r2 = c2 = 0;

        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (matrix[r][c] == a) {
                    r1 = r;
                    c1 = c;
                }
                if (matrix[r][c] == b) {
                    r2 = r;
                    c2 = c;
                }
            }
        }

        if (r1 == r2) {
            printf("%c%c", matrix[r1][(c1 + 1) % 5],
                           matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c", matrix[(r1 + 1) % 5][c1],
                           matrix[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}