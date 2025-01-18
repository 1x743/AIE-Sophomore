#include <iostream>
#include <string>
using namespace std;

// Function to calculate the sum of digits of an 8-digit number
int calculateSumOfDigits(const string& birthdate) {
    int sum = 0;
    for (char digit : birthdate) {
        // Convert each character to an integer and add to the sum
        sum += digit - '0';
    }
    return sum;
}

int main() {
    string birthdate1;

    // Input for the first birthdate
    cout << "Enter birthdate (8 digits): ";
    cin >> birthdate1;

    // Input validation for 8-digit number
    if (birthdate1.length() != 8 || !isdigit(birthdate1[0])) {
        cout << "Invalid input. Please enter an 8-digit number." << endl;
        return 1;
    }

    // Calculate sums of digits
    int sum1 = calculateSumOfDigits(birthdate1);

    // Display results
    cout << "Sum of digits for " << birthdate1 << " = " << sum1 << endl;

    return 0;
}
