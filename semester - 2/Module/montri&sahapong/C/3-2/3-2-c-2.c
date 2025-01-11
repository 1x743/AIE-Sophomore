#include <stdio.h>

int main() {
    int rows;

    // Prompt the user for input
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop to generate the pattern
    for (int i = rows; i >= 1; i--) {
        // Print spaces to create the "slip" effect
        for (int spaces = 0; spaces < rows - i; spaces++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
