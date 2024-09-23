 #pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Employee.h"
#include "Client.h" 

using namespace std;

class EmployeeManager {
private:
    static unordered_map<int, Employee*> employees; 

public:
    // Method to print the employee menu
    static void printEmployeeMenu() {
        cout << "Employee Menu:\n";
        cout << "1. New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Logout\n";
        cout << "Please choose an option: ";
    }

    // Method to create a new client
    static void newClient(Employee* employee) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID: ";
        cin >> id;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter client password: ";
        cin >> password;
        cout << "Enter initial balance: ";
        cin >> balance;

        Client* newClient = new Client(id, name, password, balance);
        employee->addClient(*newClient);
        cout << "Client added successfully.\n";
        // Add to global clients map if needed
        ClientManager::addClient(newClient);
    }

    // Method to list all clients
    static void listAllClients(Employee* employee) {
        employee->listClient();
    }

    // Method to search for a client
    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client) {
            client->display();
        }
        else {
            cout << "Client not found.\n";
        }
    }

    // Method to edit client info
    static void editClientInfo(Employee* employee) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;

        Client* client = employee->searchClient(id);
        if (client) {
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter new balance: ";
            cin >> balance;

            employee->editClient(id, name, password, balance);
            cout << "Client info updated successfully.\n";
        }
        else {
            cout << "Client not found.\n";
        }
    }

    // Method to login an employee
    static Employee* login(int id, string password) {
        auto it = employees.find(id);
        if (it != employees.end() && it->second->getPassword() == password) {
            cout << "Login successful!\n";
            return it->second;
        }
        else {
            cout << "Invalid ID or password.\n";
            return nullptr;
        }
    }

    // Method for employee options after login
    static bool employeeOptions(Employee* employee) {
        int option;

        while (true) {
            printEmployeeMenu();
            cin >> option;

            switch (option) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid option. Please try again.\n";
            }
        }
        return true; // This line is technically unreachable
    }

   
};

// Initialize static member
unordered_map<int, Employee*> EmployeeManager::employees;
