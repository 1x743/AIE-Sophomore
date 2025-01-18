#include <iostream>
#include <string>
using namespace std;

// Function to convert an 8-digit birthdate to the format dd-mm-yyyy
string formatBirthdate(const string& birthdate) {
    if (birthdate.length() != 8) {
        return "Invalid input. Please enter an 8-digit number.";
    }

    string year = birthdate.substr(0, 4);
    string month = birthdate.substr(4, 2);
    string day = birthdate.substr(6, 2);

    return day + "-" + month + "-" + year;
}

int main() {
    string birthdate1;

    // Input for the first birthdate
    cout << "Enter birthdate (8 digits): ";
    cin >> birthdate1;

    // Format and display the birthdates
    cout << "New format date for " << birthdate1 << " = " << formatBirthdate(birthdate1) << endl;

    return 0;
}
