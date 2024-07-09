// Attached: HW_10b
// ===================================================
// Program: hw10b.cpp
// ===================================================
// Programmer: Austin Monroe
// Class: CS-1C
//====================================================
//Description:
// This is sum 4 input positive numbers, and throw a negative
// number exception when a negative number is input
//=====================================================

#include <iostream>
#include <stdexcept>

using namespace std;

int getNumber() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0) {
        throw "Error. You did not enter a positive number!";
    }

    return number;
}

int main() {
    int sum = 0;

    cout << "Enter 5 positive numbers (Only numbers greater than zero)" << endl;

    try {
        for (int i = 0; i < 5; ++i) {
            int inputNumber = getNumber();
            sum += inputNumber;
        }

        cout << "The sum of the numbers is " << sum << "." << endl;
    } catch (const char* errorMsg) {
        cerr << errorMsg << endl;
    }

    return 0;
}
/*OUTPUT
Enter 5 positive numbers (Only numbers greater than zero)
Enter a number: 3
Enter a number: 5
Enter a number: 7
Enter a number: 2
Enter a number: 9
The sum of the numbers is 26.

Enter 5 positive numbers (Only numbers greater than zero)
Enter a number: 1
Enter a number: 2
Enter a number: 3
Enter a number: -4
Error. You did not enter a positive number!
*/