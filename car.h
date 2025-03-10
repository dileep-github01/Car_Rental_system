#ifndef CAR_H
#define CAR_H

#include "database.h"

class Car {
public:
    static void addCar(MYSQL* conn);
    static void viewCars(MYSQL* conn);
};

#endif

