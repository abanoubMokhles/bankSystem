#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Admin.h"
#include "Employee.h" // Ensure this includes your Employee class

using namespace std;

class AdminManager {
private:
    static unordered_map<int, Admin*> admins; // Store admins by ID

public:
    // Method to print the admin menu
    static void printAdminMenu() {
        cout << "Admin Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. List All Employees\n";
        cout << "3. Search for Employee\n";
        cout << "4. Edit Employee Info\n";
        cout << "5. Logout\n";
        cout << "Please choose an option: ";
    }

    // Method to login an admin
    static Admin* login(int id, string password) {
        auto it = admins.find(id);
        if (it != admins.end() && it->second->getPassword() == password) {
            cout << "Login successful!\n";
            return it->second;
        }
        else {
            cout << "Invalid ID or password.\n";
            return nullptr;
        }
    }

    // Method for admin options after login
    static bool AdminOptions(Admin* admin) {
        int option;

        while (true) {
            printAdminMenu();
            cin >> option;

            switch (option) {
            case 1: {
                int empId;
                string empName, empPassword;
                double empSalary;

                cout << "Enter employee ID: ";
                cin >> empId;
                cout << "Enter employee name: ";
                cin >> empName;
                cout << "Enter employee password: ";
                cin >> empPassword;
                cout << "Enter employee salary: ";
                cin >> empSalary;

                Employee* newEmployee = new Employee(empId, empName, empPassword, empSalary);
                admin->addEmployee(*newEmployee);
                cout << "Employee added successfully.\n";
                break;
            }
            case 2:
                admin->listEmployee();
                break;
            case 3: {
                int empId;
                cout << "Enter employee ID to search: ";
                cin >> empId;
                Employee* employee = admin->searchEmployee(empId);
                if (employee) {
                    employee->display();
                }
                else {
                    cout << "Employee not found.\n";
                }
                break;
            }
            case 4: {
                int empId;
                string empName, empPassword;
                double empSalary;

                cout << "Enter employee ID to edit: ";
                cin >> empId;

                Employee* employee = admin->searchEmployee(empId);
                if (employee) {
                    cout << "Enter new name: ";
                    cin >> empName;
                    cout << "Enter new password: ";
                    cin >> empPassword;
                    cout << "Enter new salary: ";
                    cin >> empSalary;

                    admin->editEmployee(empId, empName, empPassword, empSalary);
                    cout << "Employee info updated successfully.\n";
                }
                else {
                    cout << "Employee not found.\n";
                }
                break;
            }
            case 5:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid option. Please try again.\n";
            }
        }
        return true; // This line is technically unreachable
    }

    // Method to add admins (for testing purposes)
    static void addAdmin(Admin* admin) {
        admins[admin->getId()] = admin;
    }
};

// Initialize static member
unordered_map<int, Admin*> AdminManager::admins;
