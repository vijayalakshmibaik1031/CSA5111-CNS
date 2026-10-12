
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plain[100], key[] = "CIPHER";
    char cipherMap[26];
    int used[26] = {0};
    int i, j = 0;

    // Generate cipher sequence using keyword
    for (i = 0; key[i] != '\0'; i++)
    {
        int ch = toupper(key[i]) - 'A';

        if (!used[ch])
        {
            cipherMap[j++] = toupper(key[i]);
            used[ch] = 1;
        }
    }

    // Add remaining unused letters
    for (i = 0; i < 26; i++)
    {
        if (!used[i])
            cipherMap[j++] = 'A' + i;
    }

    printf("Enter plaintext: ");
    fgets(plain, sizeof(plain), stdin);

    printf("Ciphertext: ");

    for (i = 0; plain[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)plain[i]))
        {
            int index = tolower((unsigned char)plain[i]) - 'a';
            putchar(cipherMap[index]);
        }
        else
        {
            putchar(plain[i]);
        }
    }

    printf("\n");
    return 0;
}
