
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 26
#define TOP 10

char text[1000];
char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
int freq[N], order[N];

typedef struct {
    char key[N];
    double score;
} Candidate;

Candidate best[TOP];

double calculate(char key[]) {
    double expected[N] = {
        8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.2,
        0.8,4.0,2.4,6.7,7.5,1.9,0.1,6.0,6.3,9.1,
        2.8,1.0,2.4,0.2,2.0,0.1
    };
    double score = 0, count[N] = {0}, total = 0;
    int i;

    for (i = 0; text[i]; i++)
        if (isalpha(text[i])) {
            int x = toupper(text[i]) - 'A';
            count[key[x] - 'A']++;
            total++;
        }

    if (total == 0) return 999999;

    for (i = 0; i < N; i++) {
        double d = count[i] * 100 / total - expected[i];
        score += d * d / (expected[i] + 0.1);
    }
    return score;
}

void save(char key[]) {
    double s = calculate(key);
    int i, j;

    for (i = 0; i < TOP; i++) {
        if (s < best[i].score) {
            for (j = TOP - 1; j > i; j--)
                best[j] = best[j - 1];

            strcpy(best[i].key, key);
            best[i].score = s;
            break;
        }
    }
}

int main() {
    int i, j, x, y, n = 0;
    char key[N], temp;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha(text[i]))
            freq[toupper(text[i]) - 'A']++;

    for (i = 0; i < N; i++) order[i] = i;

    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
            if (freq[order[j]] > freq[order[i]]) {
                x = order[i];
                order[i] = order[j];
                order[j] = x;
            }

    for (i = 0; i < N; i++)
        key[order[i]] = english[i];

    for (i = 0; i < TOP; i++)
        best[i].score = 999999;

    save(key);

    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++) {
            strcpy((char *)text, text); /* no change to ciphertext */
            temp = key[i];
            key[i] = key[j];
            key[j] = temp;
            save(key);
            temp = key[i];
            key[i] = key[j];
            key[j] = temp;
        }

    printf("\nTop 10 possible plaintexts:\n");

    for (i = 0; i < TOP; i++) {
        printf("%d. ", i + 1);
        for (j = 0; text[j]; j++) {
            if (isupper(text[j]))
                putchar(best[i].key[text[j] - 'A']);
            else if (islower(text[j]))
                putchar(tolower(best[i].key[text[j] - 'a']));
            else
                putchar(text[j]);
        }
        printf("\n");
    }

    return 0;
}
