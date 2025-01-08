#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    // Prompt user for name
    cout << "Enter your name: ";
    getline(cin, name);

    // Prompt user for age
    cout << "Enter your age: ";
    cin >> age;

    // Display the result
    cout << "Hello " << name << ", your age is " << age << " years old." << endl;

    return 0;
}