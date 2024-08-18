#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Validation {
public:
    // Validates if the name is alphabetic and has a length between 5 and 20 characters
    static bool validateName(const string& name) {
        if (name.length() < 5 || name.length() > 20) {
            cout << "Name must be between 5 and 20 characters long." << endl;
            return false;
        }
        for (char c : name) {
            if (!isalpha(c)) {
                cout << "Name must only contain alphabetic characters." << endl;
                return false;
            }
        }
        return true;
    }

    // Validates if the password has a length between 8 and 20 characters
    static bool validatePassword(const string& password) {
        if (password.length() < 8 || password.length() > 20) {
            cout << "Password must be between 8 and 20 characters long." << endl;
            return false;
        }
        return true;
    }

    // Validates if the salary is at least 5000 (used for both Employee and Admin)
    static bool validateSalary(double salary) {
        if (salary < 5000) {
            cout << "Salary must be at least 5000." << endl;
            return false;
        }
        return true;
    }

    // Validates if the balance is at least 1500 (specific for Client)
    static bool validateBalance(double balance) {
        if (balance < 1500) {
            cout << "Balance must be at least 1500." << endl;
            return false;
        }
        return true;
    }
};
