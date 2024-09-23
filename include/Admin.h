#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <Employee.h>
using namespace std;

class Admin: public Employee {

public:
    Admin() : Employee() {

    }
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

    }
    // Setter Functions
    void setId(int adminId) {
        id = adminId;
    }

    void setName(const string& adminName) {
        if(Validation::validateName(adminName)){
            this->name = adminName;
        }
    }

    void setPassword(const string& adminPassword) {
        if(Validation::validatePassword(adminPassword)){
            this->password = adminPassword;
        }
    }

    void setSalary(double adminSalary) {
         if(Validation::validateSalary(adminSalary)){
            this->salary = adminSalary;
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

    double getSalary() {
        return salary;
    }

    // Display Function
    void display() {
        cout << "Admin ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
    void addEmployee(Employee& employee) {
        allEmployees.push_back(employee);
    }
    Employee* searchEmployee(int id) {
        for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
            if (eIt->getID() == id) return eIt._Ptr;
        }
        return NULL;
    }
    void editEmployee(int id, string name, string password, double salary) {
        searchEmployee(id)->setName(name);
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);
    }
    void listEmployee() {
        for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
            eIt->display();
            cout << "--------------------\n";
        }
    }
};

static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;
