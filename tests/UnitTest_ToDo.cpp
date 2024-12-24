#include <algorithm>

#include "CppUTest/TestHarness.h"
#include "ToDoList.h"
#include "ToDo.h"

// Test group for the ToDo class
TEST_GROUP(ToDoTests) {
  ToDoList* todo_list;

  void setup() { todo_list = new ToDoList(); }

  void teardown() { delete todo_list; }
};

TEST(ToDoTests, AddToDos) {
  ToDo todo1;
  ToDo todo2;
  // ToDo 1
  todo1.name = "Test Task 1";
  todo1.description = "Test Task 1 Description";
  todo1.status = "Todo";
  todo1.due_date = "1.1.2025";
  // ToDo 2
  todo2.name = "Test Task 2";
  todo2.description = "Test Task 2 Description";
  todo2.status = "Done";
  todo2.due_date = "31.1.2025";

  todo_list->addItem(todo1);
  todo_list->addItem(todo2);
  auto vec = todo_list->showList();
  CHECK_EQUAL(vec[0].name, "Test Task 1");
  CHECK_EQUAL(vec[0].description, "Test Task 1 Description");
  CHECK_EQUAL(vec[0].status, "Todo");
  CHECK_EQUAL(vec[0].due_date, "1.1.2025");
  CHECK_EQUAL(vec[1].name, "Test Task 2");
  CHECK_EQUAL(vec[1].description, "Test Task 2 Description");
  CHECK_EQUAL(vec[1].status, "Done");
  CHECK_EQUAL(vec[1].due_date, "31.1.2025");
}

TEST(ToDoTests, RemoveToDo) {
  ToDo todo1;
  ToDo todo2;
  // ToDo 1
  todo1.name = "Test Task 1";
  todo1.description = "Test Task 1 Description";
  todo1.status = "Todo";
  todo1.due_date = "1.1.2025";
  // ToDo 2
  todo2.name = "Test Task 2";
  todo2.description = "Test Task 2 Description";
  todo2.status = "Done";
  todo2.due_date = "31.1.2025";

  todo_list->addItem(todo1);
  todo_list->addItem(todo2);
  todo_list->removeItem(todo1);
  auto vec = todo_list->showList();
  CHECK_EQUAL(vec[0].name, "Test Task 2");
  CHECK_EQUAL(vec[0].description, "Test Task 2 Description");
  CHECK_EQUAL(vec[0].status, "Done");
  CHECK_EQUAL(vec[0].due_date, "31.1.2025");
}