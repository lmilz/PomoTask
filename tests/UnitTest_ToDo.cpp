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