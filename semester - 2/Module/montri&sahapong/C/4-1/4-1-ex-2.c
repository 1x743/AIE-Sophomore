#include <stdio.h>

int main() {
    int scores[10];
    int min, max;
    printf("กรุณาป้อนคะแนนของนักศึกษา 10 คน:\n");
    for (int i = 0; i < 10; i++) {
        printf("คะแนนของนักศึกษาคนที่ %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    min = scores[0];
    max = scores[0];
    for (int i = 1; i < 10; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    printf("\nคะแนนต่ำสุด: %d\n", min);
    printf("คะแนนสูงสุด: %d\n", max);
    return 0;
}