/*
---------------------------------------------------------
Project : Banking Management System
File    : Customer.cpp
Author  : Sharvari Bangar
Purpose : Implementation of Customer class.
---------------------------------------------------------
*/

#include "../include/Customer.h"
#include "../include/Utility.h"

#include <iostream>

using namespace std;

//=========================================================
// Default Constructor
//=========================================================

Customer::Customer()
{
    customerID = "";
    firstName = "";
    lastName = "";
    gender = "";
    dateOfBirth = "";
    phoneNumber = "";
    email = "";
    aadhaarNumber = "";
    address = "";
}

//=========================================================
// Parameterized Constructor
//=========================================================

Customer::Customer(const string& customerID,
                   const string& firstName,
                   const string& lastName,
                   const string& gender,
                   const string& dateOfBirth,
                   const string& phoneNumber,
                   const string& email,
                   const string& aadhaarNumber,
                   const string& address)
{
    this->customerID = customerID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->dateOfBirth = dateOfBirth;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->aadhaarNumber = aadhaarNumber;
    this->address = address;
}

//=========================================================
// Setter Functions
//=========================================================

void Customer::setCustomerID(const string& customerID)
{
    this->customerID = customerID;
}

void Customer::setFirstName(const string& firstName)
{
    this->firstName = firstName;
}

void Customer::setLastName(const string& lastName)
{
    this->lastName = lastName;
}

void Customer::setGender(const string& gender)
{
    this->gender = gender;
}

void Customer::setDateOfBirth(const string& dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Customer::setPhoneNumber(const string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Customer::setEmail(const string& email)
{
    this->email = email;
}

void Customer::setAadhaarNumber(const string& aadhaarNumber)
{
    this->aadhaarNumber = aadhaarNumber;
}

void Customer::setAddress(const string& address)
{
    this->address = address;
}

//=========================================================
// Getter Functions
//=========================================================

string Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

string Customer::getGender() const
{
    return gender;
}

string Customer::getDateOfBirth() const
{
    return dateOfBirth;
}

string Customer::getPhoneNumber() const
{
    return phoneNumber;
}

string Customer::getEmail() const
{
    return email;
}

string Customer::getAadhaarNumber() const
{
    return aadhaarNumber;
}

string Customer::getAddress() const
{
    return address;
}
//=========================================================
// Input Customer Details
//=========================================================

void Customer::inputCustomer()
{
    customerID = Utility::generateCustomerID();

    cout << "\n========== Customer Registration ==========\n";

    cout << "Customer ID : " << customerID << endl;

    cout << "First Name  : ";
    getline(cin, firstName);

    cout << "Last Name   : ";
    getline(cin, lastName);

    cout << "Gender      : ";
    getline(cin, gender);

    cout << "Date of Birth (DD/MM/YYYY) : ";
    getline(cin, dateOfBirth);

    while (!Utility::isValidDate(dateOfBirth))
    {
        cout << "Invalid date format. Enter again (DD/MM/YYYY): ";
        getline(cin, dateOfBirth);
    }

    cout << "Phone Number : ";
    getline(cin, phoneNumber);

    while (!Utility::isValidPhone(phoneNumber))
    {
        cout << "Invalid phone number. Enter a 10-digit number: ";
        getline(cin, phoneNumber);
    }

    cout << "Email : ";
    getline(cin, email);

    while (!Utility::isValidEmail(email))
    {
        cout << "Invalid email. Enter again: ";
        getline(cin, email);
    }

    cout << "Aadhaar Number : ";
    getline(cin, aadhaarNumber);

    while (!Utility::isValidAadhaar(aadhaarNumber))
    {
        cout << "Invalid Aadhaar number. Enter a 12-digit number: ";
        getline(cin, aadhaarNumber);
    }

    cout << "Address : ";
    getline(cin, address);
}

//=========================================================
// Display Customer Details
//=========================================================

void Customer::displayCustomer() const
{
    cout << "\n========== Customer Details ==========\n";

    cout << "Customer ID     : " << customerID << endl;
    cout << "First Name      : " << firstName << endl;
    cout << "Last Name       : " << lastName << endl;
    cout << "Gender          : " << gender << endl;
    cout << "Date of Birth   : " << dateOfBirth << endl;
    cout << "Phone Number    : " << phoneNumber << endl;
    cout << "Email           : " << email << endl;
    cout << "Aadhaar Number  : " << aadhaarNumber << endl;
    cout << "Address         : " << address << endl;
}
//=========================================================
// Serialize Customer Data
//=========================================================

string Customer::serialize() const
{
    return customerID + "|" +
           firstName + "|" +
           lastName + "|" +
           gender + "|" +
           dateOfBirth + "|" +
           phoneNumber + "|" +
           email + "|" +
           aadhaarNumber + "|" +
           address;
}

//=========================================================
// Deserialize Customer Data
//=========================================================

void Customer::deserialize(const string& data)
{
    string fields[9];
    string temp;
    int index = 0;

    for (char ch : data)
    {
        if (ch == '|')
        {
            if (index < 9)
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

    if (index < 9)
    {
        fields[index] = temp;
    }

    customerID = fields[0];
    firstName = fields[1];
    lastName = fields[2];
    gender = fields[3];
    dateOfBirth = fields[4];
    phoneNumber = fields[5];
    email = fields[6];
    aadhaarNumber = fields[7];
    address = fields[8];
}