#ifndef _DATABASE_H
#define _DATABASE_H

// Includes
#include <string>
#include <sqlite3.h>
#include <stdexcept>


class Database {
public:
    Database(const std::string& database_filename);
    virtual ~Database();

    sqlite3* getConnection();
private:
    sqlite3* database; 
};

#endif /* _DATABASE_H */