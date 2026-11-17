
#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main() {
    char p[100];
    int a,b,i,c;

    printf("Enter plaintext: ");
    scanf("%s",p);

    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);

    if(gcd(a,26)!=1) {
        printf("Encryption is not one-to-one.");
        return 0;
    }

    printf("Ciphertext: ");
    for(i=0;p[i]!='\0';i++) {
        c=((a*(p[i]-'A')+b)%26);
        printf("%c",c+'A');
    }

    return 0;
}
