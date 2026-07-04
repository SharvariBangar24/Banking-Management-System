/*
---------------------------------------------------------
Project : Banking Management System
File    : Account.cpp
Author  : Sharvari Bangar
Purpose : Implementation of Account class.
---------------------------------------------------------
*/

#include "../include/Account.h"
#include "../include/Utility.h"

#include <iostream>

using namespace std;

//=========================================================
// Default Constructor
//=========================================================

Account::Account()
{
    accountID = "";
    customerID = "";
    accountType = "";
    balance = 0.0;
    openingDate = "";
    isActive = true;
}

//=========================================================
// Parameterized Constructor
//=========================================================

Account::Account(const string& accountID,
                 const string& customerID,
                 const string& accountType,
                 double balance,
                 const string& openingDate,
                 bool isActive)
{
    this->accountID = accountID;
    this->customerID = customerID;
    this->accountType = accountType;
    this->balance = balance;
    this->openingDate = openingDate;
    this->isActive = isActive;
}

//=========================================================
// Setter Functions
//=========================================================

void Account::setAccountID(const string& accountID)
{
    this->accountID = accountID;
}

void Account::setCustomerID(const string& customerID)
{
    this->customerID = customerID;
}

void Account::setAccountType(const string& accountType)
{
    this->accountType = accountType;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

void Account::setOpeningDate(const string& openingDate)
{
    this->openingDate = openingDate;
}

void Account::setStatus(bool isActive)
{
    this->isActive = isActive;
}

//=========================================================
// Getter Functions
//=========================================================

string Account::getAccountID() const
{
    return accountID;
}

string Account::getCustomerID() const
{
    return customerID;
}

string Account::getAccountType() const
{
    return accountType;
}

double Account::getBalance() const
{
    return balance;
}

string Account::getOpeningDate() const
{
    return openingDate;
}

bool Account::getStatus() const
{
    return isActive;
}
//=========================================================
// Create Account
//=========================================================

void Account::createAccount()
{
    accountID = Utility::generateAccountID();

    cout << "\n========== Create New Account ==========\n";

    cout << "Account ID : " << accountID << endl;

    cout << "Customer ID : ";
    getline(cin, customerID);

    cout << "Account Type (Savings/Current) : ";
    getline(cin, accountType);

    while (true)
    {
        accountType = Utility::toUpper(accountType);

        if (accountType == "SAVINGS" || accountType == "CURRENT")
        {
            break;
        }

        cout << "Invalid account type.\n";
        cout << "Enter Savings or Current: ";
        getline(cin, accountType);
    }

    cout << "Initial Deposit : ";
    cin >> balance;
    cin.ignore();

    while (balance < 0)
    {
        cout << "Balance cannot be negative.\n";
        cout << "Enter Initial Deposit : ";
        cin >> balance;
        cin.ignore();
    }

    openingDate = Utility::getCurrentDate();
    isActive = true;
}

//=========================================================
// Display Account Details
//=========================================================

void Account::displayAccount() const
{
    cout << "\n========== Account Details ==========\n";

    cout << "Account ID      : " << accountID << endl;
    cout << "Customer ID     : " << customerID << endl;
    cout << "Account Type    : " << accountType << endl;
    cout << "Balance         : Rs. " << balance << endl;
    cout << "Opening Date    : " << openingDate << endl;
    cout << "Account Status  : ";

    if (isActive)
    {
        cout << "Active";
    }
    else
    {
        cout << "Inactive";
    }

    cout << endl;
}

//=========================================================
// Deposit Amount
//=========================================================

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        throw BankException("Deposit amount must be greater than zero.");
    }

    balance += amount;
}

//=========================================================
// Withdraw Amount
//=========================================================

bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw BankException("Withdrawal amount must be greater than zero.");
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;
    return true;
}
//=========================================================
// Serialize Account Data
//=========================================================

string Account::serialize() const
{
    return accountID + "|" +
           customerID + "|" +
           accountType + "|" +
           to_string(balance) + "|" +
           openingDate + "|" +
           (isActive ? "1" : "0");
}

//=========================================================
// Deserialize Account Data
//=========================================================

void Account::deserialize(const string& data)
{
    string fields[6];
    string temp;
    int index = 0;

    for (char ch : data)
    {
        if (ch == '|')
        {
            if (index < 6)
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

    if (index < 6)
    {
        fields[index] = temp;
    }

    accountID = fields[0];
    customerID = fields[1];
    accountType = fields[2];
    balance = stod(fields[3]);
    openingDate = fields[4];
    isActive = (fields[5] == "1");
}