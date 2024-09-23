#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Client.h" 

using namespace std;

class ClientManager {
private:
    static unordered_map<int, Client*> clients; 

public:
    // Method to print the client menu
    static void printClientMenu() {
        cout << "Client Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Update Password\n";
        cout << "6. Logout\n";
        cout << "Please choose an option: ";
    }

    // Method to update a person's password
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully.\n";
    }

    // Method to login a client
    static Client* login(int id, string password) {
        auto it = clients.find(id);
        if (it != clients.end() && it->second->getPassword() == password) {
            cout << "Login successful!\n";
            return it->second;
        }
        else {
            cout << "Invalid ID or password.\n";
            return nullptr;
        }
    }

    // Method for client options after login
    static bool clientOptions(Client* client) {
        int option;
        double amount;
        Client recipient;

        while (true) {
            printClientMenu();
            cin >> option;

            switch (option) {
            case 1:
                client->checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposit(amount);
                cout << "Deposit successful.\n";
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdraw(amount);
                cout << "Withdrawal successful.\n";
                break;
            case 4:
                cout << "Enter recipient ID: ";
                int recipientId;
                cin >> recipientId;
                auto recipientIt = clients.find(recipientId);
                if (recipientIt != clients.end()) {
                    cout << "Enter amount to transfer: ";
                    cin >> amount;
                    client->transferto(*(recipientIt->second), amount);
                }
                else {
                    cout << "Recipient not found.\n";
                }
                break;
            case 5:
                updatePassword(client);
                break;
            case 6:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid option. Please try again.\n";
            }
        }
        return true; 
    }

   
};

// Initialize static member
unordered_map<int, Client*> ClientManager::clients;
