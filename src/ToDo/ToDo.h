#ifndef _TODO_H
#define _TODO_H

// Includes
#include <string>

typedef struct {
    std::string name;
    std::string description;
    std::string status;
    std::string due_date;
} ToDo;

#endif /* _TODO_H */