#include <stdio.h>
int main() {
    int i = 1, j = 8;

    printf("Using while loop:\n");
    while (i <= 5) {
        printf("%d %d\n", i, j);
        i++;
        j -= 2;
    }

    i = 1;
    j = 8;

    printf("\nUsing do/while loop:\n");
    do {
        printf("%d %d\n", i, j);
        i++;
        j -= 2;
    } while (i <= 5);

    return 0;
}