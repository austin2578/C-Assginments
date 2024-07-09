// Attached: hw1a and 1b
// ===============================================================
// File: hw1b.cpp
// ===============================================================
// Programmer: Austin Monroe
// Class: CS1C
// ===============================================================
#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5;
    float testScores[SIZE] = {84, 92, 76, 81, 56};

    //range-based for loop to find the highest score
    float highestScore = testScores[0];  // initialize highest score
    for (float score : testScores) {
        if (score > highestScore) {
            highestScore = score;
        }
    }

    //display the highest score
    cout << "The highest test score is " << highestScore << ".\n";

    return 0;
}/*OUTPUT
The highest test score is 92.
*/

#include <iostream>
#include <iostream>
using namespace std;
int main()
{
const int SIZE = 5;
short int numbers[SIZE] = { 1,2,3,4,5 };
short int* intPtr;
intPtr = numbers;
for (int i = 0; i < SIZE; i++)
{
cout << intPtr << '\t' << *intPtr << endl;
intPtr++;
}
return 0;
}
/*OUTPUT
* 0x31e07ff6e6    1
* 0x31e07ff6e8    2
* 0x31e07ff6ea    3
* 0x31e07ff6ec    4
* 0x31e07ff6ee    5
*/

