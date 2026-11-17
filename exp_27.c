
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    long long e=7, n=143, c;
    int m;

    printf("Enter message: ");
    scanf("%s",msg);

    printf("Encrypted values: ");

    for(int i=0; msg[i]!='\0'; i++) {
        m=msg[i]-'A';
        c=1;

        for(int j=0; j<e; j++)
            c=(c*m)%n;

        printf("%lld ",c);
    }

    return 0;
}
