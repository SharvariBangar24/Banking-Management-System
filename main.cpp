#include <iostream>
#include "../include/Bank.h"
#include "../include/Utility.h"

using namespace std;

int main()
{
    Bank bank;
    int choice;

    do
    {
        Utility::clearScreen();

        cout << "\n====================================\n";
        cout << "   BANKING MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Create Account\n";
        cout << "4. View Accounts\n";
        cout << "5. Deposit\n";
        cout << "6. Withdraw\n";
        cout << "7. Transfer\n";
        cout << "8. View Transactions\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.addCustomer();
            Utility::pause();
            break;

        case 2:
            bank.viewAllCustomers();
            Utility::pause();
            break;

        case 3:
            bank.createAccount();
            Utility::pause();
            break;

        case 4:
            bank.viewAllAccounts();
            Utility::pause();
            break;

        case 5:
            bank.deposit();
            Utility::pause();
            break;

        case 6:
            bank.withdraw();
            Utility::pause();
            break;

        case 7:
            bank.transfer();
            Utility::pause();
            break;

        case 8:
            bank.viewAllTransactions();
            Utility::pause();
            break;

        case 0:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
            Utility::pause();
        }

    } while (choice != 0);

    return 0;
}