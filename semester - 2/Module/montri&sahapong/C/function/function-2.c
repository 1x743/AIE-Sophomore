#include <stdio.h>

// ฟังก์ชันสำหรับคำนวณผลรวม
float sum(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}

// ฟังก์ชันสำหรับคำนวณค่าเฉลี่ย
float average(float num1, float num2, float num3) {
    return sum(num1, num2, num3) / 3.0;
}

// ฟังก์ชันสำหรับหาค่ามากที่สุด
float max(float num1, float num2, float num3) {
    float maxValue = num1;
    if (num2 > maxValue) {
        maxValue = num2;
    }
    if (num3 > maxValue) {
        maxValue = num3;
    }
    return maxValue;
}

int main() {
    float num1, num2, num3;
    int choice;

    // รับค่าตัวเลขจากผู้ใช้
    printf("Enter num1: ");
    scanf("%f", &num1);
    printf("Enter num2: ");
    scanf("%f", &num2);
    printf("Enter num3: ");
    scanf("%f", &num3);

    // แสดงเมนูให้ผู้ใช้เลือก
    printf("\nPress 1: sum\n");
    printf("Press 2: average\n");
    printf("Press 3: max\n");
    printf("Choose: ");
    scanf("%d", &choice);

    // ดำเนินการตามที่ผู้ใช้เลือก
    switch (choice) {
        case 1:
            printf("Sum = %.2f\n", sum(num1, num2, num3));
            break;
        case 2:
            printf("Average = %.2f\n", average(num1, num2, num3));
            break;
        case 3:
            printf("Max = %.2f\n", max(num1, num2, num3));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
