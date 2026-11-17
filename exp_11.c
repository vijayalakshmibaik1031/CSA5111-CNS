
#include <stdio.h>
#include <math.h>

int main()
{
    double bits = 0;

    for(int i = 1; i <= 25; i++)
        bits += log2(i);

    printf("Number of possible keys = 25!\n");
    printf("Approximate power of 2 = 2^%.0f\n", bits);

    return 0;
}
