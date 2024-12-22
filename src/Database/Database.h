#ifndef _DATABASE_H
#define _DATABASE_H

// Includes
#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& database_filename);
    virtual ~Database();

    void createTable(const std::string& table_name, const std::string& schema);

private:
    sqlite3* database; 
    std::string database_name;
};

#endif /* _DATABASE_H */