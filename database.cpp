#include "database.h"

using namespace std;

MYSQL* Database::connectDB() {
    MYSQL* conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "Pandey@123", "CarRentalDB", 3306, NULL, 0);

    if (!conn) {
        cerr << "Database Connection Failed: " << mysql_error(conn) << endl;
        exit(1);
    }

    return conn;
}
