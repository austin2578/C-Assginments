#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5;
    string cities[SIZE] = {"Vienna", "Paris", "Stockholm", "New York", "Tokyo"};

    //range-based for loop to output cities
    for (float city : cities) {
        cout << city << endl;
    }

    return 0;
}/*OUTPUT
The highest test score is 92.
*/