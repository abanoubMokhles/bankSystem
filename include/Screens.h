#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Screens {
public:
    // Method to display the bank name
    static void bankName() {
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "            Route Bank             \n";
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    }

    // Method to display a welcome message
    static void welcome() {
        cout << "Welcome to Route Bank.\n";
    }

    // Method to display login options
    static void loginOptions() {
        cout << "Login Options:\n";
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
        cout << "Please choose an option: ";
    }

    // Method to get login type
    static int loginAs() {
        int choice;
        cout << "Enter your choice (1-4): ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        return choice;
    }

    // Method to display invalid choice message
    static void invalid(int c) {
        cout << "Invalid option: " << c << ". Please try again.\n";
    }

    // Method to display logout message
    static void logout() {
        cout << "You have been logged out successfully.\n";
    }

    // Method to display login screen based on role
    static void loginScreen(int c) {
        switch (c) {
        case 1:
            cout << "Client Login:\n";
            break;
        case 2:
            cout << "Employee Login:\n";
            break;
        case 3:
            cout << "Admin Login:\n";
            break;
        default:
            cout << "Unknown login type.\n";
            break;
        }
    }

    // Method to run the application
    static void runApp() {
        bankName();
        welcome();

        while (true) {
            loginOptions();
            int choice = loginAs();

            if (choice == 4) {
                cout << "Exiting the application. Goodbye!\n";
                break;
            }

            loginScreen(choice);

            int id;
            string password;

            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your password: ";
            cin >> password;

            switch (choice) {
            case 1: { // Client Login
                Client* client = ClientManager::login(id, password);
                if (client) {
                    // Handle client options after successful login
                    ClientManager::clientOptions(client);
                }
                break;
            }
            case 2: { // Employee Login
                Employee* employee = EmployeeManager::login(id, password);
                if (employee) {
                    // Handle employee options after successful login
                    EmployeeManager::employeeOptions(employee);
                }
                break;
            }
            case 3: { // Admin Login
                Admin* admin = AdminManager::login(id, password);
                if (admin) {
                    // Handle admin options after successful login
                    AdminManager::AdminOptions(admin);
                }
                break;
            }
            default:
                invalid(choice);
                break;
            }

            cout << "\n"; 
        }
    }

};
