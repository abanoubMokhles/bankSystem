#include <iostream>
#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

int main() {
    // Optionally, initialize some sample data for testing
    Admin* admin1 = new Admin(1, "Admin1", "adminpass", 5000);
    AdminManager::addAdmin(admin1);

    Employee* employee1 = new Employee(2, "Employee1", "emp1pass", 3000);
    EmployeeManager::addEmployee(employee1);

    Client* client1 = new Client(3, "Client1", "client1pass", 2000);
    ClientManager::addClient(client1);

    // Run the application
    Screens::runApp();

    // Clean up memory if needed
    delete admin1;
    delete employee1;
    delete client1;

    return 0;
}
