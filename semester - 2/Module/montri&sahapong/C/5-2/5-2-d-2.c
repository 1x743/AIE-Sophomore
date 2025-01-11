#include <stdio.h>

#define ROWS 3
#define COLS 2

void inputMatrix(int M[ROWS][COLS]) {
    printf("Enter elements of Matrix M[%dx%d]\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("M[%d][%d]: ", i+1, j+1);
            scanf("%d", &M[i][j]);
        }
    }
}

int min(int M[ROWS][COLS]) {
    int minimum = M[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (M[i][j] < minimum) {
                minimum = M[i][j];
            }
        }
    }
    return minimum;
}

int max(int M[ROWS][COLS]) {
    int maximum = M[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (M[i][j] > maximum) {
                maximum = M[i][j];
            }
        }
    }
    return maximum;
}

int main() {
    int matrix[ROWS][COLS];
    inputMatrix(matrix);

    printf("Matrix\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int minimum = min(matrix);
    int maximum = max(matrix);

    printf("Min = %d\n", minimum);
    printf("Max = %d\n", maximum);

    return 0;
}
