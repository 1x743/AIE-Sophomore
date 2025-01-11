#include <stdio.h>

int main() {
    float totalSales, commission;

    // รับยอดขายจากผู้ใช้
    printf("Enter total sales: ");
    scanf("%f", &totalSales);

    // คำนวณค่าคอมมิชชั่นตามช่วงยอดขาย
    if (totalSales < 1000) {
        commission = 0; // ยอดขายน้อยกว่า 1000 ไม่มีค่าคอมมิชชั่น
    } else if (totalSales <= 5000) {
        commission = totalSales * 0.07; // ค่าคอมมิชชั่น 7%
    } else if (totalSales <= 10000) {
        commission = totalSales * 0.10; // ค่าคอมมิชชั่น 10%
    } else {
        commission = totalSales * 0.10 + 800; // ค่าคอมมิชชั่น 10% และบวกเพิ่มอีก 800 บาท
    }

    // แสดงผลค่าคอมมิชชั่น
    printf("Sales commission: %.2f\n", commission);

    return 0;
}