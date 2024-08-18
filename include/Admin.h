#include <iostream>
#include <string>
#include <cctype>
#include <Employee.h>
using namespace std;

class Admin: public Employee {

public:
    Admin():Employee() {}
    Admin(string &name, string &password, int id, double salary): Employee(name, password,id, salary){
    }
    // Setter Functions
    void setId(int adminId) {
        id = adminId;
    }

    void setName(const string& adminName) {
        if(Validation::validateName(adminName)){
            this->name = adminName;
        }
        /*if (adminName.length() >= 5 && adminName.length() <= 20) {
            for (char c : adminName) {
                if (!isalpha(c)) {
                    cout << "Name must only contain alphabetic characters." << endl;
                    return;
                }
            }
            name = adminName;
        } else {
            cout << "Name must be between 5 and 20 characters long." << endl;
        }*/
    }

    void setPassword(const string& adminPassword) {
        if(Validation::validatePassword(adminPassword)){
            this->password = adminPassword;
        }
        /*if (adminPassword.length() >= 8 && adminPassword.length() <= 20) {
            password = adminPassword;
        } else {
            cout << "Password must be between 8 and 20 characters long." << endl;
        }*/
    }

    void setSalary(double adminSalary) {
         if(Validation::validateSalary(adminSalary)){
            this->salary = adminSalary;
        }
        /*if (adminSalary >= 5000) {
            this->salary = adminSalary;
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
        cout << "Admin ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};
