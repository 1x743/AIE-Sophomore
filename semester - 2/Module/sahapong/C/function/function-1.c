#include <stdio.h>

// ฟังก์ชันสำหรับคำนวณค่าเฉลี่ย
float average(float num1, float num2, float num3) {
    return (num1 + num2 + num3) / 3.0;
}

int main() {
    float num1, num2, num3, avg;

    // รับค่าตัวเลขจากผู้ใช้
    printf("Enter num1: ");
    scanf("%f", &num1);
    printf("Enter num2: ");
    scanf("%f", &num2);
    printf("Enter num3: ");
    scanf("%f", &num3);

    // คำนวณค่าเฉลี่ย
    avg = average(num1, num2, num3);

    // แสดงผลค่าเฉลี่ย
    printf("Average = %.2f\n", avg);

    return 0;
}
