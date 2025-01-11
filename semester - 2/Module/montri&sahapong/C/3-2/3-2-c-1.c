#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        printf("%d %d\n", i, i * 7);
    }
    printf("Press any key to continue...\n");
    getchar();
    return 0;
}