/*
---------------------------------------------------------
Project : Banking Management System
File    : Utility.h
Author  : Sharvari Bangar
Purpose : Common helper functions used throughout the
          application.
---------------------------------------------------------
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <exception>

namespace Utility
{
    //===============================
    // Validation Functions
    //===============================

    bool isValidEmail(const std::string& email);
    bool isValidPhone(const std::string& phone);
    bool isValidAadhaar(const std::string& aadhaar);
    bool isValidDate(const std::string& date);

    //===============================
    // String Utilities
    //===============================

    std::string trim(const std::string& str);
    std::string toUpper(std::string str);
    std::string toLower(std::string str);

    //===============================
    // ID Generators
    //===============================

    std::string generateCustomerID();
    std::string generateAccountID();
    std::string generateTransactionID();

    //===============================
    // Date & Time
    //===============================

    std::string getCurrentDate();
    std::string getCurrentTime();

    //===============================
    // Security
    //===============================

    std::string hashPassword(const std::string& password);

    //===============================
    // Console Functions
    //===============================

    void printHeader(const std::string& title);
    void printLine(char symbol = '=', int length = 60);
    void clearScreen();
    void pause();
}

//===================================
// Custom Exception Class
//===================================

class BankException : public std::exception
{
private:
    std::string message;

public:
    explicit BankException(const std::string& msg);

    const char* what() const noexcept override;
};

#endif