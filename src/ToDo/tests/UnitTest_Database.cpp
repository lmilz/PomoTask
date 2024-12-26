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

#include <gtest/gtest.h>

#include <filesystem>
#include <stdexcept>

#include "Database.h"
#include "SQLUtil.h"

TEST(DatabaseTest, SQLStatement)
{
    EXPECT_EQ("INSERT OR REPLACE INTO data (name, description, status, due_to) VALUES (?, ?, ?, ?);", SQLUtil::getInsertOrReplaceStatement);
    EXPECT_EQ("SELECT iname, description, status, due_to FROM data;", SQLUtil::getSelectAllStatement);
}

TEST(DatabaseTest, OpenDatabase)
{
    Database* db = new Database(":memory:");  // create data in memory

    EXPECT_NE(db, nullptr);

    delete db;
}

TEST(DatabaseTest, InvalidPathDatabase)
{
    EXPECT_THROW(Database* db = new Database("invalid_path/non_existent.db"),
                 std::runtime_error);  // invald path and non existing database
}

TEST(DatabaseTest, SaveAndFetchData)
{
    ToDoDTO dto = { .name="Test Task", .description = "Description", .status = "Open", .due_date = "1.1.2025"};
    Database* db = new Database(":memory:");  // create data in memory
    ASSERT_NO_THROW(db->save(dto));

    auto results = db->fetchAll();
    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].name, "Test Task");
    EXPECT_EQ(results[0].description, "Description");
    EXPECT_EQ(results[0].status, "Open");
    EXPECT_EQ(results[0].due_date, "1.1.2025");
    delete db;    
}