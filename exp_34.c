
#include <stdio.h>
#include <string.h>

int main() {
    char data[100], padded[200];
    int block, len, pad, i;

    printf("Enter binary plaintext: ");
    scanf("%s", data);

    printf("Enter block size: ");
    scanf("%d", &block);

    len = strlen(data);
    pad = block - (len % block);

    if(pad == 0)
        pad = block;

    strcpy(padded, data);
    padded[len] = '1';

    for(i=1; i<pad; i++)
        padded[len+i] = '0';

    padded[len+pad] = '\0';

    printf("Original Plaintext: %s\n",data);
    printf("Padded Plaintext: %s\n",padded);

    return 0;
}
