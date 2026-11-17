
#include <stdio.h>

int gcd(int a, int b) {
    while(b) {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main() {
    int p=11, q=13, n, phi;
    int e=7, d;

    n=p*q;
    phi=(p-1)*(q-1);

    for(d=1; d<phi; d++) {
        if((e*d)%phi==1)
            break;
    }

    printf("RSA Key Generation\n");
    printf("Modulus n = %d\n",n);
    printf("Public Key e = %d\n",e);
    printf("Private Key d = %d\n",d);

    printf("\nIf private key leaks, changing e and d");
    printf(" with the same n is NOT safe.\n");
    printf("Generate a new modulus instead.\n");

    return 0;
}
