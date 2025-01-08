#include <iostream>
using namespace std;

int main() {
    int score;

    // Prompt user for their score
    cout << "Enter your score: ";
    cin >> score;

    // Determine the grade
    if (score >= 80 && score <= 100) {
        cout << "Your grade is A" << endl;
    } else if (score >= 70 && score <= 79) {
        cout << "Your grade is B" << endl;
    } else if (score >= 60 && score <= 69) {
        cout << "Your grade is C" << endl;
    } else if (score >= 50 && score <= 59) {
        cout << "Your grade is D" << endl;
    } else if (score < 50 && score >= 0) {
        cout << "Your grade is F" << endl;
    } else {
        cout << "Invalid score. Please enter a score between 0 and 100." << endl;
    }

    return 0;
}
