#include "Database.h"

Database::Database(const std::string& database_filename) {
    if (sqlite3_open(database_filename.c_str(), &database) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database: " + database_filename);
    }
}

Database::~Database() {
    sqlite3_close(database);
}

sqlite3* Database::getConnection() {
    return database;
}