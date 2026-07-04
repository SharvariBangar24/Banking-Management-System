/*
---------------------------------------------------------
Project : Banking Management System
File    : FileManager.cpp
Author  : Sharvari Bangar
Purpose : Implementation of file operations.
---------------------------------------------------------
*/

#include "../include/FileManager.h"
#include "../include/Customer.h"
#include "../include/Account.h"       
#include "../include/Transaction.h"   
#include <fstream>
#include <iostream>

using namespace std;

//=========================================================
// File Paths
//=========================================================

static const string CUSTOMER_FILE = "data/customers.txt";

//=========================================================
// Save Customer
//=========================================================

void FileManager::saveCustomer(const string& data)
{
    ofstream file(CUSTOMER_FILE, ios::app);

    if (!file)
    {
        cout << "Error opening customer file for writing!\n";
        return;
    }

    file << data << endl;

    file.close();
}

//=========================================================
// Load Customers
//=========================================================

void FileManager::loadCustomers()
{
    ifstream file(CUSTOMER_FILE);

    if (!file)
    {
        cout << "No customer file found.\n";
        return;
    }

    string line;
    Customer customer;

    cout << "\n========== ALL CUSTOMERS ==========\n";

    while (getline(file, line))
    {
        if (line.empty()) continue;

        customer.deserialize(line);
        customer.displayCustomer();
    }

    file.close();
}

/*
=========================================================
Account File Operations
=========================================================
*/

static const string ACCOUNT_FILE = "data/accounts.txt";

//=========================================================
// Save Account
//=========================================================

void FileManager::saveAccount(const string& data)
{
    ofstream file(ACCOUNT_FILE, ios::app);

    if (!file)
    {
        cout << "Error opening account file for writing!\n";
        return;
    }

    file << data << endl;

    file.close();
}

//=========================================================
// Load Accounts
//=========================================================

void FileManager::loadAccounts()
{
    ifstream file(ACCOUNT_FILE);

    if (!file)
    {
        cout << "No account file found.\n";
        return;
    }

    string line;

    cout << "\n========== ALL ACCOUNTS ==========\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

/*
=========================================================
Transaction File Operations
=========================================================
*/

static const string TRANSACTION_FILE = "data/transactions.txt";

//=========================================================
// Save Transaction
//=========================================================

void FileManager::saveTransaction(const string& data)
{
    ofstream file(TRANSACTION_FILE, ios::app);

    if (!file)
    {
        cout << "Error opening transaction file for writing!\n";
        return;
    }

    file << data << endl;

    file.close();
}

//=========================================================
// Load Transactions
//=========================================================

void FileManager::loadTransactions()
{
    ifstream file(TRANSACTION_FILE);

    if (!file)
    {
        cout << "No transaction file found.\n";
        return;
    }

    string line;

    cout << "\n========== ALL TRANSACTIONS ==========\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}