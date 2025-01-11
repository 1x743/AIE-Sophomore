#include <stdio.h>

// Prototype of grading function
void grading(int N, float score[100], char grade[100]);

int main() {
    int N, i;
    float score[100];
    char grade[100];

    // Input number of students
    printf("Enter number of students N: ");
    scanf("%d", &N);

    // Validate the number of students
    if (N > 100 || N <= 0) {
        printf("Invalid number of students. Please enter a value between 1 and 100.\n");
        return 1;
    }

    // Input scores for each student
    for (i = 0; i < N; i++) {
        printf("Score of student %d: ", i + 1);
        scanf("%f", &score[i]);
    }

    // Call grading function to calculate grades
    grading(N, score, grade);

    // Display grade report with alignment
    printf("-----------------------------\n");
    printf("Grade Report Score Grade\n");
    for (i = 0; i < N; i++) {
        printf("Student %d\t%.1f\t%c\n", i + 1, score[i], grade[i]);
    }

    return 0;
}

// Grading function
void grading(int N, float score[100], char grade[100]) {
    int i;
    for (i = 0; i < N; i++) {
        if (score[i] >= 50.0) {
            grade[i] = 'P'; // Pass
        } else {
            grade[i] = 'F'; // Fail
        }
    }
}
