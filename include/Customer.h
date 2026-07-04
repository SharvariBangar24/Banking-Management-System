/*
---------------------------------------------------------
Project : Banking Management System
File    : Customer.h
Author  : Sharvari Bangar
Purpose : Customer class declaration.
---------------------------------------------------------
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string customerID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string email;
    std::string aadhaarNumber;
    std::string address;

public:

    //=====================================
    // Constructors
    //=====================================

    Customer();
    Customer(const std::string& customerID,
             const std::string& firstName,
             const std::string& lastName,
             const std::string& gender,
             const std::string& dateOfBirth,
             const std::string& phoneNumber,
             const std::string& email,
             const std::string& aadhaarNumber,
             const std::string& address);

    //=====================================
    // Setters
    //=====================================

    void setCustomerID(const std::string& customerID);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setGender(const std::string& gender);
    void setDateOfBirth(const std::string& dateOfBirth);
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);
    void setAadhaarNumber(const std::string& aadhaarNumber);
    void setAddress(const std::string& address);

    //=====================================
    // Getters
    //=====================================

    std::string getCustomerID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    std::string getDateOfBirth() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getAadhaarNumber() const;
    std::string getAddress() const;

    //=====================================
    // Member Functions
    //=====================================

    void inputCustomer();
    void displayCustomer() const;

    std::string serialize() const;
    void deserialize(const std::string& data);
};

#endif