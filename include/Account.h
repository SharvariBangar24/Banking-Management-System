/*
---------------------------------------------------------
Project : Banking Management System
File    : Account.h
Author  : Sharvari Bangar
Purpose : Account class declaration.
---------------------------------------------------------
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
    std::string accountID;
    std::string customerID;
    std::string accountType;
    double balance;
    std::string openingDate;
    bool isActive;

public:

    //=====================================
    // Constructors
    //=====================================

    Account();

    Account(const std::string& accountID,
            const std::string& customerID,
            const std::string& accountType,
            double balance,
            const std::string& openingDate,
            bool isActive);

    //=====================================
    // Setters
    //=====================================

    void setAccountID(const std::string& accountID);
    void setCustomerID(const std::string& customerID);
    void setAccountType(const std::string& accountType);
    void setBalance(double balance);
    void setOpeningDate(const std::string& openingDate);
    void setStatus(bool isActive);

    //=====================================
    // Getters
    //=====================================

    std::string getAccountID() const;
    std::string getCustomerID() const;
    std::string getAccountType() const;
    double getBalance() const;
    std::string getOpeningDate() const;
    bool getStatus() const;

    //=====================================
    // Member Functions
    //=====================================

    void createAccount();
    void displayAccount() const;

    void deposit(double amount);
    bool withdraw(double amount);

    std::string serialize() const;
    void deserialize(const std::string& data);
};

#endif