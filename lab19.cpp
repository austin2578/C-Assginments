#include <iostream>
#include <cstring>

using namespace std;

extern "C" {
    void String_length(char*);
}

int main() {
    char str[] = "Cat in the hat.";

    // Using C++ string and strlen function
    cout << "C++ String: " << str << " C++ String length= " << strlen(str) << endl;

    // Using assembly language function String_length
    String_length(str);
    cout << "ASM length= " << str << endl;

    return 0;
}