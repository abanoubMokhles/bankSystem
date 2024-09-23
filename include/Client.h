#pragma once
#include <iostream>
#include <string>
#include <Person.h>
using namespace std;

class Client: public Person {
private:
    // Attributes
    double balance;

public:
    //  Constructor
    Client(int id, string name, string password, double balance): Person(name, password, id) {
        this->id = id;
        this->balance = balance < 1500 ? 1500 : balance;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setPassword(string password) {
        this->password = password;
    }

    // Getters
    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    string getPassword() {
        return password;
    }

    double getBalance() {
        return balance;
    }

    double withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else {
            cout << "Amount not enough\n";
        }
        return balance;
    }

    double deposit(double amount) {
        balance += amount;
        return balance;
    }

    double transferto(Client& recipient, double amount) {
        if (amount <= balance) {
            balance -= amount;
            recipient.deposit(amount);
        }
        else {
            cout << "Amount not enough\n";
        }
        return balance;
    }

    void checkBalance() {
        cout << "Balance: " << balance << endl;
    }

    // Method
    void display() {
        cout << "Name = " << name << endl;
        cout << "Id = " << id << endl;
        cout << "Password = " << password << endl;
        cout << "Balance = " << balance << endl;
        cout << "\n=======================\n";
    }
};
