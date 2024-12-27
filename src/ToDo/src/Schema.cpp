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

#include "Schema.h"

Schema::Schema(sqlite3* database) : db(database) {}

int Schema::getCurrentVersion() {
    const char* sql = "PRAGMA user_version;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to fetch schema version");
    }

    int version = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        version = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return version;
}

void Schema::setVersion(int version) {
    std::string sql = "PRAGMA user_version = " + std::to_string(version) + ";";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to set schema version");
    }
}

void Schema::migrate() {
    int currentVersion = getCurrentVersion();

    if (currentVersion < 1) {
        const char* sql = R"(
            CREATE TABLE data (
                id TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                value TEXT,
                created_at TEXT,
                updated_at TEXT
            );
        )";
        if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Migration to version 1 failed");
        }
        setVersion(1);
    }
}