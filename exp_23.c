
#include <stdio.h>

int P10[]={3,5,2,7,4,10,1,9,8,6};
int P8[]={6,3,7,4,8,5,10,9};
int IP[]={2,6,3,1,4,8,5,7};
int IPI[]={4,1,3,5,7,2,8,6};
int EP[]={4,1,2,3,2,3,4,1};
int P4[]={2,4,3,1};
int S0[4][4]={{1,0,3,2},{3,2,1,0},
              {0,2,1,3},{3,1,3,2}};
int S1[4][4]={{0,1,2,3},{2,0,1,3},
              {3,0,1,0},{2,1,0,3}};

int perm(int x,int *p,int n,int len) {
    int y=0,i;
    for(i=0;i<len;i++)
        y=(y<<1)|((x>>(n-p[i]))&1);
    return y;
}

int ls(int x,int n) {
    return ((x<<n)&31)|(x>>(5-n));
}

void keys(int key,int *k1,int *k2) {
    int x=perm(key,P10,10,10);
    int l=x>>5,r=x&31;
    l=ls(l,1); r=ls(r,1);
    *k1=perm((l<<5)|r,P8,10,8);
    l=ls(l,2); r=ls(r,2);
    *k2=perm((l<<5)|r,P8,10,8);
}

int sb(int x,int s[4][4]) {
    int row=((x&8)>>2)|(x&1);
    int col=(x>>1)&3;
    return s[row][col];
}

int fk(int x,int k) {
    int l=x>>4,r=x&15;
    int t=perm(r,EP,4,8)^k;
    int b=(sb(t>>4,S0)<<2)|sb(t&15,S1);
    return ((l^perm(b,P4,4,4))<<4)|r;
}

int encrypt(int x,int k1,int k2) {
    x=perm(x,IP,8,8);
    x=fk(x,k1);
    x=((x&15)<<4)|(x>>4);
    x=fk(x,k2);
    return perm(x,IPI,8,8);
}

int main() {
    int k1,k2,i,counter=0;
    int p[]={1,2,4},c[3],d[3];
    keys(509,&k1,&k2);  /* Binary key: 0111111101 */

    printf("Encrypted: ");
    for(i=0;i<3;i++) {
        c[i]=p[i]^encrypt(counter++,k1,k2);
        printf("%08d ", 
          (c[i]/128)*10000000+(c[i]%128/64)*1000000);
        /* Display below using bit format */
        for(int j=7;j>=0;j--)
            printf("%d",(c[i]>>j)&1);
        printf(" ");
    }

    counter=0;
    printf("\nDecrypted: ");
    for(i=0;i<3;i++) {
        d[i]=c[i]^encrypt(counter++,k1,k2);
        for(int j=7;j>=0;j--)
            printf("%d",(d[i]>>j)&1);
        printf(" ");
    }
    return 0;
}
