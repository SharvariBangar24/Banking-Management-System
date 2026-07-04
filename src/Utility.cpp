/*
---------------------------------------------------------
Project : Banking Management System
File    : Utility.cpp
Author  : Sharvari Bangar
Purpose : Implementation of common helper functions.
---------------------------------------------------------
*/

#include "../include/Utility.h"

#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <functional>
#ifdef _WIN32
#include <cstdlib>
#endif

using namespace std;

namespace Utility
{

//=========================================================
// Console Functions
//=========================================================

void printLine(char symbol, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << symbol;
    }

    cout << endl;
}

void printHeader(const string& title)
{
    printLine();

    cout << title << endl;

    printLine();
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
//=========================================================
// Validation Functions
//=========================================================

bool isValidEmail(const string& email)
{
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    return (atPos != string::npos &&
            dotPos != string::npos &&
            atPos > 0 &&
            dotPos > atPos + 1 &&
            dotPos < email.length() - 1);
}

bool isValidPhone(const string& phone)
{
    if (phone.length() != 10)
    {
        return false;
    }

    for (char ch : phone)
    {
        if (!isdigit(static_cast<unsigned char>(ch)))
        {
            return false;
        }
    }

    return true;
}

bool isValidAadhaar(const string& aadhaar)
{
    if (aadhaar.length() != 12)
    {
        return false;
    }

    for (char ch : aadhaar)
    {
        if (!isdigit(static_cast<unsigned char>(ch)))
        {
            return false;
        }
    }

    return true;
}

bool isValidDate(const string& date)
{
    if (date.length() != 10)
    {
        return false;
    }

    if (date[2] != '/' || date[5] != '/')
    {
        return false;
    }

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 2 || i == 5)
        {
            continue;
        }

        if (!isdigit(static_cast<unsigned char>(date[i])))
        {
            return false;
        }
    }

    return true;
}

//=========================================================
// String Utility Functions
//=========================================================

string trim(const string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");

    if (first == string::npos)
    {
        return "";
    }

    size_t last = str.find_last_not_of(" \t\n\r");

    return str.substr(first, last - first + 1);
}

string toUpper(string str)
{
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char ch)
              {
                  return toupper(ch);
              });

    return str;
}

string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char ch)
              {
                  return tolower(ch);
              });

    return str;
}
//=========================================================
// ID Generator Functions
//=========================================================

string generateCustomerID()
{
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> dist(100000, 999999);

    return "CUS" + to_string(dist(generator));
}

string generateAccountID()
{
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> dist(10000000, 99999999);

    return "ACC" + to_string(dist(generator));
}

string generateTransactionID()
{
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> dist(100000000, 999999999);

    return "TXN" + to_string(dist(generator));
}

//=========================================================
// Date & Time Functions
//=========================================================

string getCurrentDate()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&currentTime);

    stringstream ss;

    ss << setfill('0')
       << setw(2) << localTime->tm_mday << "/"
       << setw(2) << (localTime->tm_mon + 1) << "/"
       << (localTime->tm_year + 1900);

    return ss.str();
}

string getCurrentTime()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&currentTime);

    stringstream ss;

    ss << setfill('0')
       << setw(2) << localTime->tm_hour << ":"
       << setw(2) << localTime->tm_min << ":"
       << setw(2) << localTime->tm_sec;

    return ss.str();
}
//=========================================================
// Security Functions
//=========================================================

string hashPassword(const string& password)
{
    hash<string> hasher;

    size_t hashedValue = hasher(password);

    return to_string(hashedValue);
}

} // namespace Utility


//=========================================================
// BankException Class
//=========================================================

BankException::BankException(const string& msg)
    : message(msg)
{
}

const char* BankException::what() const noexcept
{
    return message.c_str();
}