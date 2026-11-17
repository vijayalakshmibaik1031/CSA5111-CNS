
#include <stdio.h>

long long power(int a, int x, int q) {
    long long r=1;
    for(int i=0; i<x; i++)
        r=(r*a)%q;
    return r;
}

int main() {
    int q=23, a=5;
    int x=6, y=15;
    long long A, B, K1, K2;

    A=power(a,x,q);
    B=power(a,y,q);

    K1=power(B,x,q);
    K2=power(A,y,q);

    printf("Alice Public Value = %lld\n",A);
    printf("Bob Public Value = %lld\n",B);
    printf("Alice Shared Key = %lld\n",K1);
    printf("Bob Shared Key = %lld\n",K2);

    return 0;
}
