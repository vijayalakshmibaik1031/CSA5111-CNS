
#include <stdio.h>

int main()
{
    printf("ECB and CBC Error Propagation\n");

    printf("\nECB Mode:\n");
    printf("Error in C1 affects only P1.\n");
    printf("P2 and other blocks remain unchanged.\n");

    printf("\nCBC Mode:\n");
    printf("Error in C1 affects P1 and P2.\n");
    printf("P3 and other blocks remain unchanged.\n");

    printf("\nSource Plaintext Error:\n");
    printf("Error in P1 affects all ciphertext blocks.\n");
    printf("At receiver, all plaintext blocks are affected.\n");

    return 0;
}
