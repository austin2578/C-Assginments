#include <iostream> 
#include <string> 
#include <stack> 
#include "linkstack.cpp"
#include "linkedQueue.h"
using namespace std; 

int main() 
{ 
stack<string> stringStack;  // stack is LIFO 
stack<string> tempStringStack;
stack<double> doubleStack;
stack<double> tempDoubleStack;
linkedStackType<string> stringLinkedStack;
linkedStackType<double> numberLinkedStack;
linkedStackType<string> tempStringLinkedStack;
linkedStackType<double> tempNumberLinkedStack;
linkedQueueType<string> stringLinkedQueue;
linkedQueueType<double> numberLinkedQueue;
linkedQueueType<string> tempStringLinkedQueue;
linkedQueueType<double> tempNumberLinkedQueue;
string poppedName;
double poppedNumber;
string queueName;
double queueNumber;
int STRING = 5;
int DOUBLE = 6;
string names[5] = {"JoAnn","Alan","Maria","Jordyn","Eric"};
double numbers[6] = {29.39,2022.9,123.45,88.64,444.44,123.123};
//Part A
for(int i=0;i<STRING;i++)
{
    stringStack.push(names[i]);
    cout << "Added " << names[i] << " to name stack.\n";
}
for(int i=0;i<DOUBLE;i++)
{
    doubleStack.push(numbers[i]);
    cout << "Added " << numbers[i] << " to number stack.\n";
}
//Part B
while(!stringStack.empty())
{
    if(stringStack.top() == "Jordyn")
    {
        stringStack.pop();
        cout << "Removed Jordyn from the stack.\n";
        if(!tempStringStack.empty())
        {
            while(!tempStringStack.empty())
            {
                stringStack.push(tempStringStack.top());
                tempStringStack.pop();
            }
        }
        break;
    } else
    {
        tempStringStack.push(stringStack.top());
        stringStack.pop();
    }
}
cout << "Remaining elements:\n";
while(!stringStack.empty())
{
    cout << stringStack.top() << endl;
    stringStack.pop(); 
}
while(!doubleStack.empty())
{
    if(doubleStack.top() == 2022.9)
    {
        doubleStack.pop();
        cout << "Removed 2022.9 from the stack.\n";
        if(!tempDoubleStack.empty())
        {
            while(!tempDoubleStack.empty())
            {
                doubleStack.push(tempDoubleStack.top());
                tempDoubleStack.pop();
            }
        }
        break;
    } else
    {
        tempDoubleStack.push(doubleStack.top());
        doubleStack.pop();
    }
}
cout << "Remaining elements:\n";
while(!doubleStack.empty())
{
    cout << doubleStack.top() << endl;
    doubleStack.pop(); 
}
//Part C
for(int i=0;i<STRING;i++)
{
    stringLinkedStack.push(names[i]);
    cout << "Added " << names[i] << " to name linked stack.\n";
}
for(int i=0;i<DOUBLE;i++)
{
    numberLinkedStack.push(numbers[i]);
    cout << "Added " << numbers[i] << " to number linked stack.\n";
}
//Part D
while(!stringLinkedStack.isEmptyStack())
{
    stringLinkedStack.pop(poppedName);
    if(poppedName == "Jordyn")
    {
        cout << "Removed Jordyn from the stack.\n";
        if(!tempStringLinkedStack.isEmptyStack())
        {
            while(!tempStringLinkedStack.isEmptyStack())
            {
                tempStringLinkedStack.pop(poppedName);
                stringLinkedStack.push(poppedName);
            }
        }
        break;
    } else{
        tempStringLinkedStack.push(poppedName);
    }
}
cout << "Remaining elements:\n";
while(!stringLinkedStack.isEmptyStack())
{
    stringLinkedStack.pop(poppedName);
    cout << poppedName << endl; 
}
while(!numberLinkedStack.isEmptyStack())
{
    numberLinkedStack.pop(poppedNumber);
    if(poppedNumber == 2022.9)
    {
        cout << "Removed 2022.9 from the stack.\n";
        if(!tempNumberLinkedStack.isEmptyStack())
        {
            while(!tempNumberLinkedStack.isEmptyStack())
            {
                tempNumberLinkedStack.pop(poppedNumber);
                numberLinkedStack.push(poppedNumber);
            }
        }
        break;
    } else
    {
        tempNumberLinkedStack.push(poppedNumber);
    }
}
cout << "Remaining elements:\n";
while(!numberLinkedStack.isEmptyStack())
{
    numberLinkedStack.pop(poppedNumber);
    cout << poppedNumber << endl; 
}
//Part E
stringLinkedQueue.initializeQueue();
numberLinkedQueue.initializeQueue();
for(int i=0;i<STRING;i++)
{
    stringLinkedQueue.addQueue(names[i]);
    cout << "Added " << names[i] << " to name linked queue.\n";
}
for(int i=0;i<DOUBLE;i++)
{
    numberLinkedQueue.addQueue(numbers[i]);
    cout << "Added " << numbers[i] << " to number linked queue.\n";
}
//Part F
tempStringLinkedStack.destroyStack();
while(!stringLinkedQueue.isEmptyQueue())
{
    stringLinkedQueue.deQueue(queueName);
    if(queueName != "Alan")
    {
        tempStringLinkedQueue.addQueue(queueName);
    }
}
while(!tempStringLinkedQueue.isEmptyQueue())
{
    tempStringLinkedQueue.deQueue(queueName);
    stringLinkedQueue.addQueue(queueName);
}
cout << "Remaining elements:\n";
while(!stringLinkedQueue.isEmptyQueue())
{
    stringLinkedQueue.deQueue(queueName);
    cout << queueName<< endl; 
}
tempNumberLinkedStack.destroyStack();
while(!numberLinkedQueue.isEmptyQueue())
{
    numberLinkedQueue.deQueue(queueNumber);
    if(queueNumber != 2022.9)
    {
        tempNumberLinkedQueue.addQueue(queueNumber);
    }
}
while(!tempNumberLinkedQueue.isEmptyQueue())
{
    tempNumberLinkedQueue.deQueue(queueNumber);
    numberLinkedQueue.addQueue(queueNumber);
}
cout << "Remaining elements:\n";
while(!numberLinkedQueue.isEmptyQueue())
{
    numberLinkedQueue.deQueue(queueNumber);
    cout << queueNumber<< endl; 
}
//Part G
return 0; 
}