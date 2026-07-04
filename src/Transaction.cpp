/*
---------------------------------------------------------
Project : Banking Management System
File    : Transaction.cpp
Author  : Sharvari Bangar
Purpose : Implementation of Transaction class.
---------------------------------------------------------
*/

#include "../include/Transaction.h"
#include "../include/Utility.h"

#include <iostream>

using namespace std;

//=========================================================
// Default Constructor
//=========================================================

Transaction::Transaction()
{
    transactionID = "";
    accountID = "";
    transactionType = "";
    amount = 0.0;
    transactionDate = "";
    transactionTime = "";
    remarks = "";
}

//=========================================================
// Parameterized Constructor
//=========================================================

Transaction::Transaction(const string& transactionID,
                         const string& accountID,
                         const string& transactionType,
                         double amount,
                         const string& transactionDate,
                         const string& transactionTime,
                         const string& remarks)
{
    this->transactionID = transactionID;
    this->accountID = accountID;
    this->transactionType = transactionType;
    this->amount = amount;
    this->transactionDate = transactionDate;
    this->transactionTime = transactionTime;
    this->remarks = remarks;
}

//=========================================================
// Setter Functions
//=========================================================

void Transaction::setTransactionID(const string& transactionID)
{
    this->transactionID = transactionID;
}

void Transaction::setAccountID(const string& accountID)
{
    this->accountID = accountID;
}

void Transaction::setTransactionType(const string& transactionType)
{
    this->transactionType = transactionType;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

void Transaction::setTransactionDate(const string& transactionDate)
{
    this->transactionDate = transactionDate;
}

void Transaction::setTransactionTime(const string& transactionTime)
{
    this->transactionTime = transactionTime;
}

void Transaction::setRemarks(const string& remarks)
{
    this->remarks = remarks;
}

//=========================================================
// Getter Functions
//=========================================================

string Transaction::getTransactionID() const
{
    return transactionID;
}

string Transaction::getAccountID() const
{
    return accountID;
}

string Transaction::getTransactionType() const
{
    return transactionType;
}

double Transaction::getAmount() const
{
    return amount;
}

string Transaction::getTransactionDate() const
{
    return transactionDate;
}

string Transaction::getTransactionTime() const
{
    return transactionTime;
}

string Transaction::getRemarks() const
{
    return remarks;
}
//=========================================================
// Create Transaction
//=========================================================

void Transaction::createTransaction()
{
    transactionID = Utility::generateTransactionID();
    transactionDate = Utility::getCurrentDate();
    transactionTime = Utility::getCurrentTime();

    cout << "\n========== Create Transaction ==========\n";

    cout << "Transaction ID : " << transactionID << endl;

    cout << "Account ID     : ";
    getline(cin, accountID);

    cout << "Transaction Type (DEPOSIT/WITHDRAWAL/TRANSFER): ";
    getline(cin, transactionType);

    // Convert to uppercase for consistency
    transactionType = Utility::toUpper(transactionType);

    cout << "Amount         : ";
    cin >> amount;
    cin.ignore();

    while (amount <= 0)
    {
        cout << "Invalid amount. Enter again: ";
        cin >> amount;
        cin.ignore();
    }

    cout << "Remarks        : ";
    getline(cin, remarks);
}

//=========================================================
// Display Transaction
//=========================================================

void Transaction::displayTransaction() const
{
    cout << "\n========== Transaction Details ==========\n";

    cout << "Transaction ID   : " << transactionID << endl;
    cout << "Account ID       : " << accountID << endl;
    cout << "Type             : " << transactionType << endl;
    cout << "Amount           : Rs. " << amount << endl;
    cout << "Date             : " << transactionDate << endl;
    cout << "Time             : " << transactionTime << endl;
    cout << "Remarks          : " << remarks << endl;
}
//=========================================================
// Serialize Transaction Data
//=========================================================

string Transaction::serialize() const
{
    return transactionID + "|" +
           accountID + "|" +
           transactionType + "|" +
           to_string(amount) + "|" +
           transactionDate + "|" +
           transactionTime + "|" +
           remarks;
}

//=========================================================
// Deserialize Transaction Data
//=========================================================

void Transaction::deserialize(const string& data)
{
    string fields[7];
    string temp;
    int index = 0;

    for (char ch : data)
    {
        if (ch == '|')
        {
            if (index < 7)
            {
                fields[index++] = temp;
                temp.clear();
            }
        }
        else
        {
            temp += ch;
        }
    }

    if (index < 7)
    {
        fields[index] = temp;
    }

    transactionID = fields[0];
    accountID = fields[1];
    transactionType = fields[2];
    amount = stod(fields[3]);
    transactionDate = fields[4];
    transactionTime = fields[5];
    remarks = fields[6];
}