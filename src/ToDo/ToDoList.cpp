#include "ToDoList.h"

ToDoList::ToDoList() {}

void ToDoList::addItem(const ToDo& todo) { todo_list.push_back(todo); }

void ToDoList::removeItem(const ToDo& todo) {
    auto iter = std::find_if(todo_list.begin(), todo_list.end(), [&todo](const ToDo& e) {
        return e.name == todo.name &&
               e.description == todo.description &&
               e.status == todo.status &&
               e.due_date == todo.due_date;
    });

    if (iter != todo_list.end()) {
        todo_list.erase(iter);
    }
}

std::vector<ToDo> ToDoList::showList() const { return todo_list; }