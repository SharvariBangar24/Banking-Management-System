/*
---------------------------------------------------------
Project : Banking Management System
File    : Bank.cpp
Author  : Sharvari Bangar
Purpose : Core banking logic implementation.
---------------------------------------------------------
*/

#include "../include/Bank.h"
#include "../include/Utility.h"
#include "../include/FileManager.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//=========================================================
// Add Customer
//=========================================================

void Bank::addCustomer()
{
    Customer customer;

    cin.ignore(); // clear input buffer
    customer.inputCustomer();

    FileManager::saveCustomer(customer.serialize());

    cout << "\nCustomer added successfully!\n";
}

//=========================================================
// View All Customers
//=========================================================

void Bank::viewAllCustomers()
{
    FileManager::loadCustomers();
}

/*
=========================================================
Account Operations
=========================================================
*/

void Bank::createAccount()
{
    Account account;

    cin.ignore(); // clear input buffer
    account.createAccount();

    FileManager::saveAccount(account.serialize());

    cout << "\nAccount created successfully!\n";
}

//=========================================================
// View All Accounts
//=========================================================

void Bank::viewAllAccounts()
{
    FileManager::loadAccounts();
}
void Bank::deposit()
{
    Transaction txn;

    string accId = selectAccountFromList();
    if (accId == "") return;

    txn.createTransaction();

    txn.setAccountID(accId);
    txn.setTransactionType("DEPOSIT");

    FileManager::saveTransaction(txn.serialize());

    updateAccountBalance(accId, txn.getAmount(), true); // 💰 UPDATE BALANCE

    cout << "\nDeposit successful!\n";
}
void Bank::withdraw()
{
    Transaction txn;

    string accId = selectAccountFromList();
    if (accId == "") return;

    txn.createTransaction();

    txn.setAccountID(accId);
    txn.setTransactionType("WITHDRAWAL");

    FileManager::saveTransaction(txn.serialize());

    updateAccountBalance(accId, txn.getAmount(), false); // 💰 UPDATE BALANCE

    cout << "\nWithdrawal successful!\n";
}
void Bank::transfer()
{
    Transaction txn;

    cout << "\nFROM ACCOUNT:\n";
    string fromAcc = selectAccountFromList();

    if (fromAcc == "") return;

    cout << "\nTO ACCOUNT:\n";
    string toAcc = selectAccountFromList();

    if (toAcc == "") return;

    txn.createTransaction();

    txn.setAccountID(fromAcc + " -> " + toAcc);
    txn.setTransactionType("TRANSFER");

    FileManager::saveTransaction(txn.serialize());

    cout << "\nTransfer recorded successfully!\n";
}
void Bank::viewAllTransactions()
{
    FileManager::loadTransactions();
}
string Bank::selectAccountFromList()
{
    ifstream file("data/accounts.txt");

    vector<Account> accounts;

    if (!file)
    {
        cout << "No accounts found.\n";
        return "";
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        Account acc;
        acc.deserialize(line);
        accounts.push_back(acc);
    }

    file.close();

    if (accounts.empty())
    {
        cout << "No accounts available.\n";
        return "";
    }

    cout << "\n========== SELECT ACCOUNT ==========\n";

    for (int i = 0; i < accounts.size(); i++)
    {
        cout << i + 1 << ". "
             << accounts[i].getAccountID()
             << " | " << accounts[i].getAccountType()
             << " | Balance: " << accounts[i].getBalance()
             << endl;
    }

    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice < 1 || choice > accounts.size())
    {
        cout << "Invalid selection!\n";
        return "";
    }

    return accounts[choice - 1].getAccountID();
}
void Bank::updateAccountBalance(const string& accountID, double amount, bool isDeposit)
{
    ifstream file("data/accounts.txt");
    vector<Account> accounts;

    if (!file)
    {
        cout << "Account file not found!\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        Account acc;
        acc.deserialize(line);

        if (acc.getAccountID() == accountID)
        {
            double balance = acc.getBalance();

            if (isDeposit)
                balance += amount;
            else
            {
                if (balance < amount)
                {
                    cout << "Insufficient balance!\n";
                    return;
                }
                balance -= amount;
            }

            acc.setBalance(balance);
        }

        accounts.push_back(acc);
    }

    file.close();

    // rewrite file
    ofstream out("data/accounts.txt");

    for (Account& a : accounts)
    {
        out << a.serialize() << endl;
    }

    out.close();
}