#include "car.h"
#include "customer.h"

using namespace std;

int main() {
    MYSQL* conn = Database::connectDB();
    int choice;

    while (true) {
        cout << "\nCar Rental System\n";
        cout << "1. Add Car\n2. View Cars\n3. Register Customer\n4. Rent a Car\n5. Exit\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: Car::addCar(conn); break;
            case 2: Car::viewCars(conn); break;
            case 3: Customer::registerCustomer(conn); break;
            case 4: Customer::rentCar(conn); break;
            case 5: mysql_close(conn); return 0;
            default: cout << "Invalid Choice!\n";
        }
    }
}
