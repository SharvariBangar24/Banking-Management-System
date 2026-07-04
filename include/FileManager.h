/*
---------------------------------------------------------
Project : Banking Management System
File    : FileManager.h
Author  : Sharvari Bangar
Purpose : Handles file operations for Customers,
          Accounts, and Transactions.
---------------------------------------------------------
*/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:

    //=====================================
    // Customer File Operations
    //=====================================

    static void saveCustomer(const std::string& data);
    static void loadCustomers();

    //=====================================
    // Account File Operations
    //=====================================

    static void saveAccount(const std::string& data);
    static void loadAccounts();

    //=====================================
    // Transaction File Operations
    //=====================================

    static void saveTransaction(const std::string& data);
    static void loadTransactions();
};

#endif