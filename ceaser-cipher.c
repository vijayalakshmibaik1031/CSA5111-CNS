#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int key, i;

    printf("Enter the text: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + key) % 26 + 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + key) % 26 + 'a';
        }
    }

    printf("Encrypted text: %s", str);

    return 0;
}