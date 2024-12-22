#include "ToDoList.h"

ToDoList::ToDoList() {}

void ToDoList::addItem(const std::string& todo) { todo_list.push_back(todo); }

void ToDoList::removeItem(const std::size_t index) {
  if (index >= todo_list.size())
    return;

  todo_list.erase(todo_list.begin() + index);
}

void ToDoList::removeItem(const std::string& todo) {
  auto iter = std::find(todo_list.begin(), todo_list.end(), todo);
  todo_list.erase(iter);
}

std::vector<std::string> ToDoList::showList() const { return todo_list; }