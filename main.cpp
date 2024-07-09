#include "Grad.h"
#include <iostream>
int main()
{
//Student student; <-- Error. Cannot instantiate an abstract class
Grad graduate_1(12345, "Tom Lee", "PhD");
Grad graduate_2;
graduate_2.setID(33333);
graduate_2.setName("Kim Jones");
graduate_2.setProgram("MS");
cout << "Grad student #1:\n";
graduate_1.showStudent();
cout << "Grad student #2:\n";
graduate_2.showStudent();
return 0;
}
// ============================================================
/*OUTPUT
Grad student #1:
ID: 12345
Name: Tom Lee
Program: PhD
Grad student #2:
ID: 33333
Name: Kim Jones
Program: MS
*/