#include <stdio.h>
int main() {
    int Dido[5];
    float Fifa[3] = {4.5, 10.5, 20.5};
    printf("\nกรุณาป้อนค่าให้กับสมาชิกของอาร์เรย์ Dido:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dido[%d] = ", i);
        scanf("%d", &Dido[i]);
    }
    printf("\nค่าของตัวแปร Fifa:\n");
    for (int i = 0; i < 3; i++) {
        printf("Fifa[%d] = %.2f\n", i, Fifa[i]);
    }
    printf("\nค่าของตัวแปร Dido:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dido[%d] = %d\n", i, Dido[i]);
    }
    printf("\nกรุณาป้อนค่าใหม่ให้กับสมาชิกของอาร์เรย์ Fifa:\n");
    for (int i = 0; i < 3; i++) {
        printf("Fifa[%d] = ", i);
        scanf("%f", &Fifa[i]);
    }
    printf("\nค่าของตัวแปร Fifa หลังการอัปเดต:\n");
    for (int i = 0; i < 3; i++) {
        printf("Fifa[%d] = %.2f\n", i, Fifa[i]);
    }
    printf("\nค่าของตัวแปร Dido:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dido[%d] = %d\n", i, Dido[i]);
    }
    float sumDido = 0, sumFifa = 0;
    for (int i = 0; i < 5; i++) {
        sumDido += Dido[i];
    }
    for (int i = 0; i < 3; i++) {
        sumFifa += Fifa[i];
    }
    float totalSum = sumDido + sumFifa;
    int totalElements = 5 + 3;
    float avgTotal = totalSum / totalElements;
    printf("\nค่าเฉลี่ยรวมของ Dido และ Fifa = %.4f\n", avgTotal);
    return 0;
}