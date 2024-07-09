#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main()
 {
    int array[] = {12, 24, 49, 9, 59, 288, 19, 13, 888, 77, 25, 109, 55, 118, 89, 33, 1001, 18, 44, 88};
    int i, j;
    int size = sizeof(array)/sizeof(array[0]);
    LinkedBinaryTree tree;
    for (i = 0; i < size - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
    for (i = size - 1; i >= 0; i--) 
    cout << array[i] << ", ";
    cout << endl << size;
    tree.addRoot();
    tree.expandExternal(root)    

    
 }