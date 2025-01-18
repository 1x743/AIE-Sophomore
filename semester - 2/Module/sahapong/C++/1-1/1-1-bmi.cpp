#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Variables for input
    int currentYear, birthYear;
    double weight, height;

    // Input current year, birth year, weight, and height
    cout << "Enter current year: ";
    cin >> currentYear;
    cout << "Enter your birth year: ";
    cin >> birthYear;
    cout << "Enter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (cm): ";
    cin >> height;

    // Calculate age
    int age = currentYear - birthYear;

    // Calculate BMI
    double heightInMeters = height / 100.0;
    double bmi = weight / (heightInMeters * heightInMeters);

    // Calculate BMR using Harris-Benedict Equation
    // For Men: BMR = 66 + (13.7 * weight in kg) + (5 * height in cm) - (6.8 * age in years)
    double bmrMale = 66.5 + (13.75 * weight) + (5.003 * height) - (6.75 * age);

    // Output results
    cout << fixed << setprecision(2);
    cout << "\nYour age: " << age << " years" << endl;
    cout << "Your BMI: " << bmi << endl;
    cout << "Your BMR (male): " << bmrMale << endl;

    return 0;
}
