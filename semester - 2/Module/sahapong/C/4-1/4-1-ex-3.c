#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int found = 0;
    printf("กรุณาป้อนข้อความ: ");
    scanf("%s", str);
    printf("ตำแหน่งของตัวอักษร 'a': ");
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("ไม่มีตัวอักษร 'a' ในข้อความที่ป้อน");
    }
    printf("\n");
    return 0;
}