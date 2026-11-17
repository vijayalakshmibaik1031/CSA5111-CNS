
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher[] = "KHOOR ZRUOG";

double freq[] = {
    8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,
    0.2,0.8,4.0,2.4,6.7,7.5,1.9,0.1,6.0,
    6.3,9.1,2.8,1.0,2.4,0.2,2.0,0.1
};

int main()
{
    char result[26][100];
    double score[26];

    for(int k=0;k<26;k++)
    {
        int count[26]={0}, total=0;
        strcpy(result[k],cipher);

        for(int i=0;result[k][i];i++)
        {
            if(isalpha(result[k][i]))
            {
                int c=toupper(result[k][i])-'A';
                int p=(c-k+26)%26;

                result[k][i]=p+'A';
                count[p]++;
                total++;
            }
        }

        score[k]=0;

        for(int i=0;i<26;i++)
            score[k]+=count[i]*freq[i];
    }

    printf("Top 10 Possible Plaintexts:\n");

    for(int n=0;n<10;n++)
    {
        int best=-1;

        for(int k=0;k<26;k++)
            if(score[k]>=0 &&
              (best==-1 || score[k]>score[best]))
                best=k;

        printf("Key %2d: %s\n",best,result[best]);
        score[best]=-1;
    }

    return 0;
}
