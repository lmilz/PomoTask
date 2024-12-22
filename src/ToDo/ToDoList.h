#ifndef _TODO_LIST_H
#define _TODO_LIST_H

// Includes
#include <algorithm>
#include <string>
#include <vector>

class ToDoList {
 public:
  ToDoList();

  void addItem(const std::string& todo);
  void removeItem(const std::size_t index);
  void removeItem(const std::string& todo);
  std::vector<std::string> showList() const;

 private:
  std::vector<std::string> todo_list;
};

#endif /* _TODO_LIST_H */