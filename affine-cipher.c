#include <stdio.h>

int main()
{
    char s[100];
    int a, b, i, x;

    printf("Enter text: ");
    scanf("%s", s);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    for(i = 0; s[i] != '\0'; i++)
    {
        x = s[i] - 'A';
        s[i] = ((a * x + b) % 26) + 'A';
    }

    printf("Encrypted text: %s", s);

    return 0;
}