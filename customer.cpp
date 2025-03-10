#include "customer.h"

using namespace std;

void Customer::registerCustomer(MYSQL* conn) {
    string name, phone;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Phone: ";
    cin >> phone;

    string query = "INSERT INTO Customers (Name, Phone) VALUES ('" + name + "', '" + phone + "')";
    if (mysql_query(conn, query.c_str()) == 0)
        cout << "Customer Registered Successfully!\n";
    else
        cerr << "Error: " << mysql_error(conn) << "\n";
}

void Customer::rentCar(MYSQL* conn) {
    int customerID, serial;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Car Serial: ";
    cin >> serial;

    string query = "UPDATE Cars SET Avail = 0 WHERE Serial = " + to_string(serial);
    mysql_query(conn, query.c_str());

    query = "UPDATE Customers SET RentedCar = " + to_string(serial) + " WHERE ID = " + to_string(customerID);
    mysql_query(conn, query.c_str());

    cout << "Car Rented Successfully!\n";
}

void Customer::returnCar(MYSQL* conn) {
    int customerID;
    cout << "Enter Customer ID: ";
    cin >> customerID;

    // Retrieve the rented car serial from the customer record
    string query = "SELECT RentedCar FROM Customers WHERE ID = " + to_string(customerID);
    mysql_query(conn, query.c_str());

    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);

    if (!row || !row[0]) {
        cout << "No car rented by this customer.\n";
        mysql_free_result(res);
        return;
    }

    int serial = stoi(row[0]);
    mysql_free_result(res);

    // Mark the car as available again
    query = "UPDATE Cars SET Avail = 1 WHERE Serial = " + to_string(serial);
    mysql_query(conn, query.c_str());

    // Remove the rented car entry from the customer record
    query = "UPDATE Customers SET RentedCar = NULL WHERE ID = " + to_string(customerID);
    mysql_query(conn, query.c_str());

    cout << "Car Returned Successfully!\n";
}
