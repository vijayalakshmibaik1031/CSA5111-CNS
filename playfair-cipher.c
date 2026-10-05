#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[30], text[100], a[5][5];
    int used[26] = {0}, r, c, i, j, k = 0;

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter text: ");
    scanf("%s", text);

    /* Create 5x5 matrix */
    for(i = 0; key[i]; i++)
    {
        char ch = toupper(key[i]);
        if(ch == 'J') ch = 'I';

        if(!used[ch-'A'])
        {
            a[k/5][k%5] = ch;
            used[ch-'A'] = 1;
            k++;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(i == ('J'-'A')) continue;

        if(!used[i])
        {
            a[k/5][k%5] = 'A' + i;
            used[i] = 1;
            k++;
        }
    }

    /* Encryption */
    for(i = 0; text[i] && text[i+1]; i += 2)
    {
        char x = toupper(text[i]);
        char y = toupper(text[i+1]);

        if(x == 'J') x = 'I';
        if(y == 'J') y = 'I';

        for(r = 0; r < 5; r++)
            for(c = 0; c < 5; c++)
            {
                if(a[r][c] == x) { int r1=r,c1=c;
                    for(j=0;j<5;j++)
                        for(k=0;k<5;k++)
                            if(a[j][k]==y)
                            {
                                int r2=j,c2=k;
                                if(r1==r2)
                                    printf("%c%c",a[r1][(c1+1)%5],
                                                 a[r2][(c2+1)%5]);
                                else if(c1==c2)
                                    printf("%c%c",a[(r1+1)%5][c1],
                                                 a[(r2+1)%5][c2]);
                                else
                                    printf("%c%c",a[r1][c2],a[r2][c1]);
                            }
                }
            }
    }

    return 0;
}