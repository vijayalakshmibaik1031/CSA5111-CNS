
#include <stdio.h>

int perm(int x, int *p, int n, int bits)
{
    int out = 0;
    for(int i = 0; i < n; i++)
        out = (out << 1) | ((x >> (bits-p[i])) & 1);
    return out;
}

int s0[4][4] = {
    {1,0,3,2}, {3,2,1,0},
    {0,2,1,3}, {3,1,3,2}
};

int s1[4][4] = {
    {0,1,2,3}, {2,0,1,3},
    {3,0,1,0}, {2,1,0,3}
};

void generate(int key, int *k1, int *k2)
{
    int p10[] = {3,5,2,7,4,10,1,9,8,6};
    int p8[] = {6,3,7,4,8,5,10,9};

    int x = perm(key,p10,10,10);
    int l = x >> 5, r = x & 31;

    l = ((l << 1) | (l >> 4)) & 31;
    r = ((r << 1) | (r >> 4)) & 31;

    *k1 = perm((l << 5) | r,p8,8,10);

    l = ((l << 2) | (l >> 3)) & 31;
    r = ((r << 2) | (r >> 3)) & 31;

    *k2 = perm((l << 5) | r,p8,8,10);
}

int F(int r, int key)
{
    int ep[] = {4,1,2,3,2,3,4,1};
    int p4[] = {2,4,3,1};

    int x = perm(r,ep,8,4) ^ key;
    int a = x >> 4, b = x & 15;

    int row1 = ((a & 8) >> 2) | (a & 1);
    int col1 = (a >> 1) & 3;

    int row2 = ((b & 8) >> 2) | (b & 1);
    int col2 = (b >> 1) & 3;

    return perm((s0[row1][col1] << 2) |
                 s1[row2][col2],p4,4,4);
}

int fk(int x, int key)
{
    int l = x >> 4, r = x & 15;
    return ((l ^ F(r,key)) << 4) | r;
}

int sdes(int x, int k1, int k2, int decrypt)
{
    int ip[] = {2,6,3,1,4,8,5,7};
    int ipi[] = {4,1,3,5,7,2,8,6};

    x = perm(x,ip,8,8);

    if(decrypt) {
        x = fk(x,k2);
        x = ((x & 15) << 4) | (x >> 4);
        x = fk(x,k1);
    }
    else {
        x = fk(x,k1);
        x = ((x & 15) << 4) | (x >> 4);
        x = fk(x,k2);
    }

    return perm(x,ipi,8,8);
}

int main()
{
    int key = 0b0111111101;
    int iv = 0b10101010;

    int plain[] = {
        0b00000001,
        0b00100011
    };

    int cipher[2], recovered[2];
    int k1,k2,previous = iv;

    generate(key,&k1,&k2);

    printf("S-DES CBC Encryption\n");

    for(int i=0;i<2;i++) {
        cipher[i] = sdes(plain[i]^previous,k1,k2,0);
        previous = cipher[i];
        printf("Cipher Block %d: ",i+1);
        for(int j=7;j>=0;j--)
            printf("%d",(cipher[i]>>j)&1);
        printf("\n");
    }

    printf("\nS-DES CBC Decryption\n");

    previous = iv;

    for(int i=0;i<2;i++) {
        recovered[i] = sdes(cipher[i],k1,k2,1)^previous;
        previous = cipher[i];

        printf("Plain Block %d: ",i+1);
        for(int j=7;j>=0;j--)
            printf("%d",(recovered[i]>>j)&1);
        printf("\n");
    }

    return 0;
}
