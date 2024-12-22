#include <filesystem>
#include "CppUTest/TestHarness.h"
#include "Database.h"

TEST_GROUP(DatabaseTest) {
  Database* db;
  const std::string testDbFile = "test.db";

  void setup() override {
    db = new Database(testDbFile);
    db->createTable("Users", "ID INTEGER PRIMARY KEY, Name TEXT, Age INTEGER");
  }

  void teardown() override {
    delete db;
    std::filesystem::remove(testDbFile);
  }
};

TEST(DatabaseTest, OpenDatabase) { CHECK(db != nullptr); }