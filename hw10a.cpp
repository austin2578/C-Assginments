// Attached: HW_10a
// ===================================================
// Program: hw10a.cpp
// ===================================================
// Programmer: Austin Monroe
// Class: CS-1C
//====================================================
//Description:
// This program will throw a bad memory allocation exception
// when memory cannot be allocated
//=====================================================

#include <iostream>
#include <new>

using namespace std;

int main() {
    double* ptrs[50];

    try {
        for (int i = 0; i < 50; i++) {
            ptrs[i] = new double[50000000]; // Allocate an array of 50,000,000 doubles
            cout << "ptr[" << i << "] points to 50,000,000 new doubles" << endl;
        }
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }
    // Clean up any previously allocated memory
    for (int i = 0; i < 50; i++) {
        delete[] ptrs[i];
    }
    return 0;
}
/*OUTPUT
ptr[0] points to 50,000,000 new doubles
ptr[1] points to 50,000,000 new doubles
ptr[2] points to 50,000,000 new doubles
ptr[3] points to 50,000,000 new doubles
ptr[4] points to 50,000,000 new doubles
ptr[5] points to 50,000,000 new doubles
ptr[6] points to 50,000,000 new doubles
ptr[7] points to 50,000,000 new doubles
ptr[8] points to 50,000,000 new doubles
ptr[9] points to 50,000,000 new doubles
ptr[10] points to 50,000,000 new doubles
ptr[11] points to 50,000,000 new doubles
ptr[12] points to 50,000,000 new doubles
ptr[13] points to 50,000,000 new doubles
ptr[14] points to 50,000,000 new doubles
ptr[15] points to 50,000,000 new doubles
ptr[16] points to 50,000,000 new doubles
ptr[17] points to 50,000,000 new doubles
ptr[18] points to 50,000,000 new doubles
ptr[19] points to 50,000,000 new doubles
ptr[20] points to 50,000,000 new doubles
ptr[21] points to 50,000,000 new doubles
ptr[22] points to 50,000,000 new doubles
ptr[23] points to 50,000,000 new doubles
ptr[24] points to 50,000,000 new doubles
ptr[25] points to 50,000,000 new doubles
ptr[26] points to 50,000,000 new doubles
ptr[27] points to 50,000,000 new doubles
ptr[28] points to 50,000,000 new doubles
ptr[29] points to 50,000,000 new doubles
ptr[30] points to 50,000,000 new doubles
ptr[31] points to 50,000,000 new doubles
ptr[32] points to 50,000,000 new doubles
ptr[33] points to 50,000,000 new doubles
ptr[34] points to 50,000,000 new doubles
ptr[35] points to 50,000,000 new doubles
ptr[36] points to 50,000,000 new doubles
ptr[37] points to 50,000,000 new doubles
ptr[38] points to 50,000,000 new doubles
ptr[39] points to 50,000,000 new doubles
ptr[40] points to 50,000,000 new doubles
ptr[41] points to 50,000,000 new doubles
ptr[42] points to 50,000,000 new doubles
ptr[43] points to 50,000,000 new doubles
ptr[44] points to 50,000,000 new doubles
ptr[45] points to 50,000,000 new doubles
ptr[46] points to 50,000,000 new doubles
ptr[47] points to 50,000,000 new doubles
ptr[48] points to 50,000,000 new doubles
ptr[49] points to 50,000,000 new doubles
*/