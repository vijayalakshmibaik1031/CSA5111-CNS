
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char msg[] = "meet me at the usual place at ten rather than eight oclock";
    char text[100], cipher[100];
    int n=0;

    int key[2][2]={{9,4},{5,7}};
    int inv[2][2]={{15,18},{15,9}};

    for(int i=0;msg[i];i++)
        if(isalpha(msg[i]))
            text[n++]=toupper(msg[i]);

    if(n%2) text[n++]='X';

    printf("Encrypted Message: ");

    for(int i=0;i<n;i+=2)
    {
        int a=text[i]-'A';
        int b=text[i+1]-'A';

        int x=(key[0][0]*a+key[0][1]*b)%26;
        int y=(key[1][0]*a+key[1][1]*b)%26;

        cipher[i]=x+'A';
        cipher[i+1]=y+'A';

        printf("%c%c",cipher[i],cipher[i+1]);
    }

    cipher[n]='\0';

    printf("\nDecrypted Message: ");

    for(int i=0;i<n;i+=2)
    {
        int a=cipher[i]-'A';
        int b=cipher[i+1]-'A';

        printf("%c%c",
        (inv[0][0]*a+inv[0][1]*b)%26+'A',
        (inv[1][0]*a+inv[1][1]*b)%26+'A');
    }

    return 0;
}
