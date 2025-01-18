#include <iostream>
#include <limits>
using namespace std;

int main() {
    int num, maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max();

    cout << "ใส่จำนวนเต็มบวก (ใส่ จำนวนลบ เพื่อหยุด): " << endl;

    while (true) {
        cout << "ใส่ตัวเลข: ";
        cin >> num;

        if (num < 0) break; // หยุดเมื่อใส่ 0
        if (num == 0) {
            cout << "กรุณาใส่จำนวนเต็มบวกเท่านั้น!" << endl;
            continue;
        }

        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    if (maxVal == numeric_limits<int>::min()) {
        cout << "ไม่มีข้อมูลที่ถูกต้อง" << endl;
    } else {
        cout << "ค่าที่น้อยที่สุด: " << minVal << endl;
        cout << "ค่าที่มากที่สุด: " << maxVal << endl;
    }

    return 0;
}
