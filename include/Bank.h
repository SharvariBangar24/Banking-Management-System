/*
---------------------------------------------------------
Project : Banking Management System
File    : Bank.h
Author  : Sharvari Bangar
Purpose : Core controller for banking operations.
---------------------------------------------------------
*/

#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

class Bank
{
public:

    //=====================================
    // Customer Operations
    //=====================================

    void addCustomer();
    void viewAllCustomers();

    //=====================================
    // Account Operations
    //=====================================

    void createAccount();
    void viewAllAccounts();
    void updateAccountBalance(const std::string& accountID, double amount, bool isDeposit);

    //=====================================
    // Transaction Operations
    //=====================================

    void deposit();
    void withdraw();
    void transfer();
    std::string selectAccountFromList();
    void viewAllTransactions();

};

#endif