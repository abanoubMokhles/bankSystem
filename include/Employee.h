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
    Employee(){
        this->salary = 0;
    }
    Employee(string &name, string &password, int id, double salary): Person(name, password, id){
        this->salary = salary;
    }
    // Setter Functions
    void setId(int empId) {
        id = empId;
    }

    void setName(const string& empName) {
        if(Validation::validateName(empName)){
            this->name = empName;
        }
        /*if (empName.length() >= 5 && empName.length() <= 20) {
            for (char c : empName) {
                if (!isalpha(c)) {
                    cout << "Name must only contain alphabetic characters." << endl;
                    return;
                }
            }

        } else {
            cout << "Name must be between 5 and 20 characters long." << endl;
        }*/
    }

    void setPassword(const string& empPassword) {
        if(Validation::validatePassword(empPassword)){
            this->password = empPassword;
        }
        /*if (empPassword.length() >= 8 && empPassword.length() <= 20) {
            password = empPassword;
        } else {
            cout << "Password must be between 8 and 20 characters long." << endl;
        }*/
    }

    void setSalary(double empSalary) {
        if(Validation::validateSalary(empSalary)){
            this->salary = empSalary;
        }

        /*if (empSalary >= 5000) {
            salary = empSalary;
        } else {
            cout << "Salary must be at least 5000." << endl;
        }*/
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
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};
