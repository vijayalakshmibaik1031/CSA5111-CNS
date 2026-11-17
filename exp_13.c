
#include <stdio.h>

int main()
{
    int P[2][2]={{2,4},{1,3}};
    int C[2][2]={{6,20},{15,19}};

    int invP[2][2]={{25,4},{17,25}};
    int K[2][2];

    printf("Recovered Key Matrix:\n");

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            K[i][j]=0;

            for(int k=0;k<2;k++)
                K[i][j]+=C[i][k]*invP[k][j];

            K[i][j]%=26;
            printf("%d ",K[i][j]);
        }
        printf("\n");
    }

    return 0;
}
