#include <filesystem>
#include "CppUTest/TestHarness.h"
#include "Database.h"

TEST_GROUP(DatabaseTest) {
  void setup() override {
  }

  void teardown() override {
  }
};

TEST(DatabaseTest, OpenDatabase) { 
  Database* db = new Database(":memory:"); // create data in memory
  sqlite3* connection = db->getConnection();

  CHECK(connection != nullptr);
  
  delete db;
}