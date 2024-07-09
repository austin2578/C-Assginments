#include "linkstack.cpp"
#include <string>

int main()
{
   linkedStackType<string> stringLinkedStack;
   linkedStackType<double> doubleLinkedStack;
   linkedStackType<string> tempStringLinkedStack;
   linkedStackType<double> tempDoubleLinkedStack;
   string poppedName;
   double poppedNumber;
   int STRING = 5;
   int DOUBLE = 6;
   string names[5] = {"JoAnn","Alan","Maria","Jordyn","Eric"};
   double numbers[6] = {29.39,2022.9,123.45,88.64,444.44,123.123};

   stringLinkedStack.initializeStack();
   doubleLinkedStack.initializeStack();

   for(int i=0;i<STRING;i++)
   {
        stringLinkedStack.push(names[i]);
        cout << "Added " << names[i] << " to name linked stack.\n";
   }
    for(int i=0;i<DOUBLE;i++)
   {
        doubleLinkedStack.push(numbers[i]);
        cout << "Added " << numbers[i] << " to number linked stack.\n";
   }
   tempStringLinkedStack=stringLinkedStack;
   for(int i=0;i<STRING;i++)
   {
        stringLinkedStack.pop(poppedName);
        cout << "Popped " << poppedName << " in name linked stack.\n";
        tempStringLinkedStack.push(poppedName);
        if(poppedName == "Jordyn") 
        {
            
            break;
        }
        else 
   }
   return 0;
}