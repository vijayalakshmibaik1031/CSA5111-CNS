
#include <stdio.h>
#include <stdint.h>

uint64_t subkey(uint64_t x, uint64_t R) {
    if(x & 0x8000000000000000ULL)
        return (x << 1) ^ R;
    return x << 1;
}

int main() {
    uint64_t L = 0x8000000000000000ULL;
    uint64_t K1, K2;

    K1 = subkey(L, 0x1B);
    K2 = subkey(K1, 0x1B);

    printf("K1 = %016llX\n", (unsigned long long)K1);
    printf("K2 = %016llX\n", (unsigned long long)K2);

    return 0;
}
