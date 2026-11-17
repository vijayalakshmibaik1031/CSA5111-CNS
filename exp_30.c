
#include <stdio.h>

int main() {
    int X, K, T, Y, T2;

    printf("Enter message block X: ");
    scanf("%d",&X);

    printf("Enter key K: ");
    scanf("%d",&K);

    // Simple illustrative encryption function
    T = (X + K) % 256;

    Y = X ^ T;

    // CBC-MAC of two blocks
    T2 = ((Y + K) % 256);
    T2 = ((T ^ T2) + K) % 256;

    printf("One block MAC = %d\n",T);
    printf("Second block = %d\n",Y);
    printf("Two block MAC = %d\n",T2);

    return 0;
}
