// Attached: lab1
// ===============================================================
// File: lab1.cpp
// ===============================================================
// Programmer: Austin Monroe
// Class: CS1C
// ===============================================================
#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5;
    string cities[SIZE] = {"Vienna", "Paris", "Stockholm", "New York", "Tokyo"};

    //range-based for loop to output cities
    for (string city : cities) {
        cout << city << endl;
    }

    return 0;
}/*OUTPUT
Vienna
Paris
Stockholm
New York
Tokyo
*/