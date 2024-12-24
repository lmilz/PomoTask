#ifndef _TODO_LIST_H
#define _TODO_LIST_H

// Includes
#include <algorithm>
#include <string>
#include <vector>
#include "ToDo.h"

class ToDoList {
 public:
  ToDoList();

  void addItem(const ToDo& todo);
  void removeItem(const ToDo& todo);
  std::vector<ToDo> showList() const;

 private:
  std::vector<ToDo> todo_list;
};

#endif /* _TODO_LIST_H */