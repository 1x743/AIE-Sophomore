#include <stdio.h>

int main() {
    int scores[10];
    int sum = 0;
    float average;
    printf("กรุณาป้อนคะแนนของนักศึกษา 10 คน:\n");
    for (int i = 0; i < 10; i++) {
        printf("คะแนนของนักศึกษาคนที่ %d: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }
    average = sum / 10.0;
    printf("\nผลรวมของคะแนน: %d\n", sum);
    printf("ค่าเฉลี่ยของคะแนน: %.2f\n", average);
    return 0;
}