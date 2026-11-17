
#include <stdio.h>

int main()
{
    int shift[16] =
    {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    int C[28], D[28];

    for(int i=0;i<28;i++)
    {
        C[i]=i;
        D[i]=i+28;
    }

    printf("DES Subkey Generation\n");

    for(int r=0;r<16;r++)
    {
        for(int s=0;s<shift[r];s++)
        {
            int temp=C[0];

            for(int i=0;i<27;i++)
                C[i]=C[i+1];

            C[27]=temp;

            temp=D[0];

            for(int i=0;i<27;i++)
                D[i]=D[i+1];

            D[27]=temp;
        }

        printf("\nRound %d Key: ",r+1);

        for(int i=0;i<24;i++)
            printf("%d",C[i]);

        for(int i=0;i<24;i++)
            printf("%d",D[i]);
    }

    return 0;
}
