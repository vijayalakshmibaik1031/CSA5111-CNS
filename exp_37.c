
#include <stdio.h>
#include <string.h>

int main() {
    char cipher[200], plain[200];
    char freq[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26]={0}, i,j;

    printf("Enter ciphertext: ");
    fgets(cipher,sizeof(cipher),stdin);

    for(i=0;cipher[i]!='\0';i++)
        if(cipher[i]>='A' && cipher[i]<='Z')
            count[cipher[i]-'A']++;

    printf("\nPossible plaintext:\n");

    for(j=0;j<10;j++) {
        for(i=0;cipher[i]!='\0';i++) {
            if(cipher[i]>='A' && cipher[i]<='Z')
                plain[i]=freq[(cipher[i]-'A'+j)%26];
            else
                plain[i]=cipher[i];
        }
        plain[i]='\0';
        printf("%d. %s",j+1,plain);
    }

    return 0;
}
