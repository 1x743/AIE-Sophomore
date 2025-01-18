#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double PI = 3.14159;
    double radius, height, volume;

    cout << "โปรแกรมคำนวณปริมาตรกระบอกสูบ" << endl;

    cout << "กรุณาใส่รัศมี (radius): ";
    cin >> radius;

    cout << "กรุณาใส่ความสูง (height): ";
    cin >> height;

    if (radius < 0 || height < 0) {
        cout << "รัศมีและความสูงต้องเป็นค่าบวกเท่านั้น!" << endl;
    } else {
        volume = PI * pow(radius, 2) * height;
        cout << "ปริมาตรกระบอกสูบ: " << volume << " ลูกบาศก์หน่วย" << endl;
    }

    return 0;
}
