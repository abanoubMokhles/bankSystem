#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <Person.h>
#include <Validation.h>

using namespace std;

class Employee: public Person {
protected:
    double salary;

public:

    Employee() : Person() {
        salary = 0;
    }
    Employee(int id, string name, string password, double salary) : Person(id, name, password) {
        setSalary(salary);
    }
 
    // Setter Functions
    void setId(int empId) {
        id = empId;
    }

    void setName(const string& empName) {
        if(Validation::validateName(empName)){
            this->name = empName;
        }
    }

    void setPassword(const string& empPassword) {
        if(Validation::validatePassword(empPassword)){
            this->password = empPassword;
        }
    }

    // Getter Functions
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getPassword() {
        return password;
    }

    // Display Function

    void setSalary(double salary) {
        if (Validation::validateSalary(salary))
            this->salary = salary;
        else cout << "Invalid salary\n";
    }

    double getSalary() {
        return salary;
    }

    void display() {
        Person::display();
        cout << "Salary : " << salary << endl;
    }

    void addClient(Client& client) {
        allClients.push_back(client);
    }

    Client* searchClient(int id) {
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
            if (clIt->getID() == id) return clIt._Ptr;
        }
        return NULL;
    }

    void listClient() {
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
            clIt->display();
            cout << "-------------------------\n";
        }
    }

    void editClient(int id, string name, string password, double balance) {
        searchClient(id)->setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalance(balance);
    }
};
