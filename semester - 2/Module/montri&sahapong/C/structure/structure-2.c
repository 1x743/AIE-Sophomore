#include <stdio.h>

int main() {
    int number;

    // รับค่าตัวเลขจากผู้ใช้
    printf("Enter a number: ");
    scanf("%d", &number);

    // ตรวจสอบค่าตัวเลข
    if (number > 0) {
        if (number % 2 == 0) {
            printf("%d is positive even number\n", number);
        } else {
            printf("%d is positive odd number\n", number);
        }
    } else if (number < 0) {
        if (number % 2 == 0) {
            printf("%d is negative even number\n", number);
        } else {
            printf("%d is negative odd number\n", number);
        }
    } else {
        printf("0 is zero\n");
    }

    printf("Bye...\n");
    return 0;
}
