#include <stdio.h>
int main() {
    int num, i = 1, result;

    printf("Which number do you want to display: ");
    scanf("%d", &num);

    printf("%d\n", num);

    while (1) {
        result = num * (i + 1);
        if (result > 60) {
            break;
        }
        printf("%d\n", result);
        i++;
    }

    printf("Press any key to continue...\n");
    return 0;
}