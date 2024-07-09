// Attached: HW_4B
// ===================================================
// Program: Transaction.h
// =================================================== 
// Programmer: Austin Monroe
// Class: CS-4A  M-Th 1:30-3:50
// ===================================================
// Program: Transaction header
//
//====================================================
//Description:
// This header contains the transaction class and its
// its contents including ID, amount, type, and date
//=====================================================
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
public:
    // Constructors and Destructor
    Transaction();
    Transaction(int id, double amt, char type, string date);
    ~Transaction();

    //Transaction type
    char type;

    // Member Functions
    void setTransaction(int id, double amt, char type, string date);
    double getAmt() const;
    void displayTransaction() const;

private:
    //Transaction values
    int id;
    double amt;
    string date;
};

#endif