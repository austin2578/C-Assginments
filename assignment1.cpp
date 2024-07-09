#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool isPalindromeBase(string userPalindrome /*< a word or phrase as input by the user*/);
bool isPalindromeRecursive(string userPalindrome, int start /*< start index of user string*/, int end /*< end index of user string*/);
/**
* This program will take an input word
* from the user and tell the user if
* the word is a palindrome.
*/
int main()
{
    string userPalindrome;
    cout << "/********************************************\n";
    cout << "* Program Description\n";
    cout << "* -------------------------------------------\n";
    cout << "* This program will take a word and uses a\n";
    cout << "* recursive function to see if the input \n";
    cout << "* word is a Palindrome. It ignores spaces,\n";
    cout << "* capital letters, and punctuation.\n*\n*\n";
    cout << "* OUTPUT\n";
    cout << "* -------------------------------------------\n";
    cout << "* Outputs the word entered and whether it is\n";
    cout << "* a palindrome or not.\n";
    cout << "*********************************************/\n\n\n";
    cout << "Please type an input to test (Type Q/q to exit): ";  //Request for user input
    getline(cin,userPalindrome);                                  //gets user input from console, whole line
    cin.ignore(1000,10);                                         //clear buffer
    //Loop runs until quit by user
    while(1)
    {
        if(userPalindrome == "q" || userPalindrome == "Q") break;  //breaks loop when user enters Q or q
        if(isPalindromeBase(userPalindrome))                       //checks if input is a palindrome
        {
            cout << "'" << userPalindrome << "' is a palindrome.\n";       //outputs if user is a palindrome
        }else
        {
            cout << "'" << userPalindrome << "' is not palindrome.\n";     //outputs if user is not a palindrome
        }
        cout << "\nPlease type an input to test (Type Q/q to exit): ";  //Requests input continue loop
        getline(cin,userPalindrome);                                    //gets user input from console, whole line
        cin.ignore(1000,10);                                           //clear buffer
    }
    cout << "Thank you for using my program.\n";                       //outputs a thank you to console at end
    return 0;
}

/**
* This function is the base test to see
* if the user input is a palindrome.
*/
bool isPalindromeBase(string userPalindrome)
{
    if(userPalindrome.length() == 0)
    {
        //Returns true since an nothing is technically a palindrome
        return 1;    
    }
    //Removes spaces and punctuation from string
    userPalindrome.erase(remove(userPalindrome.begin(),userPalindrome.end(),' '),userPalindrome.end());
    userPalindrome.erase(remove(userPalindrome.begin(),userPalindrome.end(),','),userPalindrome.end());
    userPalindrome.erase(remove(userPalindrome.begin(),userPalindrome.end(),'?'),userPalindrome.end());
    userPalindrome.erase(remove(userPalindrome.begin(),userPalindrome.end(),'.'),userPalindrome.end());
    userPalindrome.erase(remove(userPalindrome.begin(),userPalindrome.end(),'!'),userPalindrome.end());
    //Calls the recursive function if size is greater than 0
    return isPalindromeRecursive(userPalindrome,0,userPalindrome.length()-1);   
}

/**
* This function is the recursive test to see
* if the user input is a palindrome.
*/
bool isPalindromeRecursive(string userPalindrome, int start, int end)
{
    if(start == end)
    {
        //Ends if both indexes meet meaning it is a palindrome
        return 1;
    }
    if(tolower(userPalindrome[start]) != tolower(userPalindrome[end]))
    {
        //Ends if the values of each index do not match, meaning it is not a palindrome
        return 0;
    }
    if (start < end + 1)
    { 
        //Continues recursive search if it is a palindrome until this point
        return isPalindromeRecursive(userPalindrome, start + 1, end - 1);
    }
    return 1;
}
