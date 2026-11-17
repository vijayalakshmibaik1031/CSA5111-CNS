
#include <stdio.h>

int main() {
    int h=12, p=23, q=11, g=2;
    int x=3, k1=4, k2=7;
    int r1, s1, r2, s2;
    int rsa1, rsa2;

    // DSA signatures (small illustrative values)
    r1 = (g*k1)%p % q;
    s1 = ((h+x*r1)*k1)%q;

    r2 = (g*k2)%p % q;
    s2 = ((h+x*r2)*k2)%q;

    printf("DSA Signature 1 = (%d, %d)\n",r1,s1);
    printf("DSA Signature 2 = (%d, %d)\n",r2,s2);

    // RSA deterministic signature example
    rsa1 = (h*7)%23;
    rsa2 = (h*7)%23;

    printf("RSA Signature 1 = %d\n",rsa1);
    printf("RSA Signature 2 = %d\n",rsa2);

    return 0;
}
