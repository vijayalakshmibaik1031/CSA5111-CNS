
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char msg[]="send more money";
    char plain[]="cash not needed";
    int key[]={9,0,1,7,23,15,21,14,11,11,2,8,9};
    char cipher[50];
    int i,n=0;

    printf("Encrypted Message: ");

    for(i=0;msg[i];i++)
    {
        if(isalpha(msg[i]))
        {
            int p=toupper(msg[i])-'A';
            int c=(p+key[n])%26;
            cipher[n++]=c+'A';
        }
    }

    cipher[n]='\0';
    printf("%s\n",cipher);

    printf("New Key: ");

    for(i=0;i<n;i++)
    {
        int p=toupper(plain[i])-'A';
        int c=cipher[i]-'A';
        int k=(c-p+26)%26;

        printf("%d ",k);
    }

    return 0;
}
