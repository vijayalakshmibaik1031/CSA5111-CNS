
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
}

int main()
{
    char message[] =
        "Must see you over Cadogan West. Coming at once.";
    char text[200];
    int i, n = 0, r1, c1, r2, c2;

    for (i = 0; message[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)message[i]))
        {
            char ch = toupper((unsigned char)message[i]);

            if (ch == 'J')
                ch = 'I';

            text[n++] = ch;
        }
    }

    text[n] = '\0';

    // Make digraphs; insert X between repeated letters
    char prepared[400];
    int k = 0;

    for (i = 0; i < n;)
    {
        prepared[k++] = text[i++];

        if (i < n)
        {
            if (text[i] == prepared[k - 1])
                prepared[k++] = 'X';
            else
                prepared[k++] = text[i++];
        }
        else
        {
            prepared[k++] = 'X';
        }
    }

    prepared[k] = '\0';

    printf("Prepared text: %s\n", prepared);
    printf("Encrypted text: ");

    for (i = 0; i < k; i += 2)
    {
        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            putchar(matrix[r1][(c1 + 1) % 5]);
            putchar(matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            putchar(matrix[(r1 + 1) % 5][c1]);
            putchar(matrix[(r2 + 1) % 5][c2]);
        }
        else
        {
            putchar(matrix[r1][c2]);
            putchar(matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}
