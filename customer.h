#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "database.h"

class Customer {
public:
    static void registerCustomer(MYSQL* conn);
    static void rentCar(MYSQL* conn);
    static void returnCar(MYSQL* conn);
};

#endif

