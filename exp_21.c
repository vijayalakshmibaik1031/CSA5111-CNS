
#include <stdio.h>
#include <string.h>

int main()
{
    char msg[100];
    int block = 8, n, pad;

    printf("Enter plaintext: ");
    scanf("%99s", msg);

    n = strlen(msg);
    pad = block - (n % block);

    printf("\nOriginal Message: %s", msg);
    printf("\nPadding Length: %d", pad);

    printf("\nPadded Message: %s", msg);

    printf("1");

    for(int i = 1; i < pad; i++)
        printf("0");

    printf("\n");

    return 0;
}
