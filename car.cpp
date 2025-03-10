#include "car.h"

using namespace std;

void Car::addCar(MYSQL* conn) {
    int serial, rent;
    string brand, model;

    cout << "Enter Car Serial: ";
    cin >> serial;
    cout << "Enter Car Brand: ";
    cin >> brand;
    cout << "Enter Car Model: ";
    cin >> model;
    cout << "Enter Rent Amount: ";
    cin >> rent;

    string query = "INSERT INTO Cars (Serial, Brand, Model, Rent, Avail) VALUES (" +
                   to_string(serial) + ", '" + brand + "', '" + model + "', " + to_string(rent) + ", 1)";

    if (mysql_query(conn, query.c_str()) == 0)
        cout << "Car Added Successfully!\n";
    else
        cerr << "Error: " << mysql_error(conn) << "\n";
}

void Car::viewCars(MYSQL* conn) {
    mysql_query(conn, "SELECT * FROM Cars");
    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row;

    cout << "Available Cars:\n";
    while ((row = mysql_fetch_row(res)))
        cout << "Serial: " << row[0] << ", Brand: " << row[1] << ", Model: " << row[2] << ", Rent: $" << row[3] << "\n";

    mysql_free_result(res);
}
