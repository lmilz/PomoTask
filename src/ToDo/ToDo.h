#ifndef _TODO_H
#define _TODO_H

// Includes
#include <algorithm>
#include <vector>
#include <string>

class ToDo {
public:
    ToDo();

    void addItem(const std::string& todo);
    void removeItem(const std::size_t index);
    void removeItem(const std::string& todo);
    std::vector<std::string> showList() const;
private:
    std::vector<std::string> todo_list;
};

#endif /* _TODO_H */