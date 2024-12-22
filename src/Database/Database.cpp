#include "Database.h"

Database::Database(const std::string& database_filename) : database_name(database_filename), database(nullptr) {}

Database::~Database() {
}

void Database::createTable(const std::string& table_name, const std::string& schema) {
}