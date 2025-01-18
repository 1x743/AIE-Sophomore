#include <stdio.h>

// ฟังก์ชันคำนวณ BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

int main() {
    float weight, height, bmi;

    // รับน้ำหนักและส่วนสูงจากผู้ใช้
    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    printf("Enter height (m): ");
    scanf("%f", &height);

    // คำนวณค่า BMI
    bmi = calculateBMI(weight, height);

    // แสดงผล BMI และเกณฑ์ร่างกาย
    printf("BMI = %.2f\n", bmi);
    if (bmi < 18.5) {
        printf("Category: Underweight\n");
    } else if (bmi < 25) {
        printf("Category: Normal\n");
    } else if (bmi < 30) {
        printf("Category: Overweight\n");
    } else {
        printf("Category: Obese\n");
    }

    return 0;
}