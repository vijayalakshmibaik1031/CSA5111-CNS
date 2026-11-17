
#include <stdio.h>

int mod(int x) {
    return (x%26+26)%26;
}

int main() {
    int p[2][2], c[2][2], k[2][2];
    int det, inv, i, j;

    printf("Enter plaintext matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&p[i][j]);

    printf("Enter ciphertext matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&c[i][j]);

    det=mod(p[0][0]*p[1][1]-p[0][1]*p[1][0]);

    for(inv=1;inv<26;inv++)
        if(mod(det*inv)==1)
            break;

    if(inv==26) {
        printf("Plaintext matrix has no inverse.");
        return 0;
    }

    int a[2][2]={
        {mod(p[1][1]*inv),mod(-p[0][1]*inv)},
        {mod(-p[1][0]*inv),mod(p[0][0]*inv)}
    };

    printf("Recovered Hill Key:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            k[i][j]=0;
            for(int t=0;t<2;t++)
                k[i][j]+=a[i][t]*c[t][j];
            printf("%d ",mod(k[i][j]));
        }
        printf("\n");
    }

    return 0;
}
