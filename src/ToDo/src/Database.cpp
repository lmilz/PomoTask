// MIT License
//
// Copyright (c) 2024 Lars Milz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "Database.h"

Database::Database(const std::string& database_filename)
{
    if (sqlite3_open(database_filename.c_str(), &database) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database: " + database_filename);
    }
}

Database::~Database()
{
    sqlite3_close(database);
}

void Database::save(const ToDoDTO& dto)
{
    std::string sql = SQLUtil::getInsertOrReplaceStatement();
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare save statement");
    }

    sqlite3_bind_text(statement, 1, dto.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 2, dto.description.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 3, dto.status.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 4, dto.due_date.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(statement) != SQLITE_DONE) {
        sqlite3_finalize(statement);
        throw std::runtime_error("Failed to execute save statement");
    }

    sqlite3_finalize(statement);    
}

std::vector<ToDoDTO> Database::fetchAll() {
    std::vector<ToDoDTO> results;
    const char* sql = "SELECT name, description, status, due_date FROM data;";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sql, -1, &statement, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare fetch statement");
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        ToDoDTO dto;
        dto.name = reinterpret_cast<const char*>(sqlite3_column_text(statement, 0));
        dto.description = reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
        dto.status = reinterpret_cast<const char*>(sqlite3_column_text(statement, 2));
        dto.due_date = reinterpret_cast<const char*>(sqlite3_column_text(statement, 3));
        results.push_back(dto);
    }

    sqlite3_finalize(statement);
    return results;
}