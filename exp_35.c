
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char p[100], c[100], d[100];
    int k[100], i, n;

    printf("Enter plaintext: ");
    scanf("%s",p);

    n=strlen(p);
    srand(time(NULL));

    printf("Key: ");
    for(i=0;i<n;i++) {
        k[i]=rand()%26;
        printf("%d ",k[i]);
        c[i]=((p[i]-'A'+k[i])%26)+'A';
        d[i]=((c[i]-'A'-k[i]+26)%26)+'A';
    }

    c[n]='\0';
    d[n]='\0';

    printf("\nEncrypted: %s",c);
    printf("\nDecrypted: %s",d);

    return 0;
}
