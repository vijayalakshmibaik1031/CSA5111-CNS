
#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, e, m, g;

    printf("Enter n, public key e and plaintext block: ");
    scanf("%d%d%d", &n, &e, &m);

    g = gcd(m, n);

    if(g > 1 && g < n) {
        printf("Common factor = %d\n", g);
        printf("Other factor = %d\n", n/g);
        printf("RSA modulus is factorized.\n");
    }
    else {
        printf("No useful common factor found.\n");
    }

    return 0;
}
