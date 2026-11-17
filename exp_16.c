
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[] = "WKH TXLFN EURZQ IRA";
    char plain[100];

    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int map[26];
    int n = 0;

    for(int i = 0; i < 26; i++)
        map[i] = -1;

    for(int i = 0; cipher[i]; i++)
        if(isalpha(cipher[i]))
            count[toupper(cipher[i]) - 'A']++;

    for(int i = 0; i < 26; i++)
        for(int j = i + 1; j < 26; j++)
            if(count[i] < count[j])
            {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }

    printf("Possible Plaintext:\n");

    for(int i = 0; cipher[i]; i++)
    {
        if(isalpha(cipher[i]))
        {
            int c = toupper(cipher[i]) - 'A';
            plain[n++] = english[c % 26];
        }
        else
            plain[n++] = cipher[i];
    }

    plain[n] = '\0';

    printf("%s\n", plain);

    return 0;
}
