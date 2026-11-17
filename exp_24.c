
#include <stdio.h>

int main() {
    int p=59, q=61, e=31;
    int phi=(p-1)*(q-1);
    int d;

    for(d=1; d<phi; d++) {
        if((e*d)%phi==1)
            break;
    }

    printf("p = %d\nq = %d\n",p,q);
    printf("Phi(n) = %d\n",phi);
    printf("Public Key = (%d, 3599)\n",e);
    printf("Private Key = (%d, 3599)\n",d);

    return 0;
}
