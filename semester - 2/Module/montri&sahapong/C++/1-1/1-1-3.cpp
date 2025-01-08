#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    // Prompt user for the number
    cout << "Enter number n: ";
    cin >> n;

    // Calculate the sum from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Display the result
    cout << "Sum of numbers from 1 to " << n << " is " << sum << endl;

    return 0;
}
