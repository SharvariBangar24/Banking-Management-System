/*
---------------------------------------------------------
Project : Banking Management System
File    : Transaction.h
Author  : Sharvari Bangar
Purpose : Transaction class declaration.
---------------------------------------------------------
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    std::string transactionID;
    std::string accountID;
    std::string transactionType;
    double amount;
    std::string transactionDate;
    std::string transactionTime;
    std::string remarks;

public:

    //=====================================
    // Constructors
    //=====================================

    Transaction();

    Transaction(const std::string& transactionID,
                const std::string& accountID,
                const std::string& transactionType,
                double amount,
                const std::string& transactionDate,
                const std::string& transactionTime,
                const std::string& remarks);

    //=====================================
    // Setters
    //=====================================

    void setTransactionID(const std::string& transactionID);
    void setAccountID(const std::string& accountID);
    void setTransactionType(const std::string& transactionType);
    void setAmount(double amount);
    void setTransactionDate(const std::string& transactionDate);
    void setTransactionTime(const std::string& transactionTime);
    void setRemarks(const std::string& remarks);

    //=====================================
    // Getters
    //=====================================

    std::string getTransactionID() const;
    std::string getAccountID() const;
    std::string getTransactionType() const;
    double getAmount() const;
    std::string getTransactionDate() const;
    std::string getTransactionTime() const;
    std::string getRemarks() const;

    //=====================================
    // Member Functions
    //=====================================

    void createTransaction();
    void displayTransaction() const;

    std::string serialize() const;
    void deserialize(const std::string& data);
};

#endif