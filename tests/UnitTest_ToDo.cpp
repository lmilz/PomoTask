#include <algorithm>

#include "CppUTest/TestHarness.h"
#include "ToDo.h"

// Test group for the ToDo class
TEST_GROUP(ToDoTests) {
  ToDo* todo;

  void setup() { todo = new ToDo(); }

  void teardown() { delete todo; }
};

TEST(ToDoTests, AddToDos) {
  todo->addItem("Test Task 1");
  todo->addItem("Test Task 2");
  auto vec = todo->showList();
  CHECK(std::find(vec.begin(), vec.end(), "Test Task 1") != vec.end());
  CHECK(std::find(vec.begin(), vec.end(), "Test Task 2") != vec.end());
}

TEST(ToDoTests, RemoveToDo) {
  todo->addItem("Test Task 1");
  todo->addItem("Test Task 2");
  todo->removeItem("Test Task 1");
  auto vec = todo->showList();
  CHECK(std::find(vec.begin(), vec.end(), "Test Task 1") == vec.end());
}