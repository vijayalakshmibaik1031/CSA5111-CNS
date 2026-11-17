
#include <stdio.h>

int main() {
    int rate=1024, state=1600;
    int lanes=state/64;
    int capacity=(state-rate)/64;
    int filled=lanes-capacity;
    int blocks=0;

    while(filled<lanes) {
        filled+=rate/64;
        blocks++;
    }

    printf("State size = %d bits\n",state);
    printf("Block size = %d bits\n",rate);
    printf("Capacity lanes = %d\n",capacity);
    printf("Blocks required = %d\n",blocks);

    return 0;
}
