#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>
#include <iostream>

class Database {
public:
    static MYSQL* connectDB();
};

#endif

