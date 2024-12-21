#ifndef _TODO_H
#define _TODO_H

// Includes
#include <algorithm>
#include <vector>
#include <string>

/**
 * @class ToDo
 * @brief Manages a list of ToDos .
 *
 * This class provides functionalities to add, remove, and list ToDos.
 */
class ToDo {
public:
    /**
     * @brief Constructor.
     */
    ToDo();

    /**
     * @brief Adds a new ToDo to the list.
     *
     * @param description Description of the ToDo to be added.
     */
    void addItem(const std::string& todo);

    /**
     * @brief Removes a ToDo from the list by its index.
     *
     * @param index Index of the ToDo to be removed.
     */
    void removeItem(const std::size_t index);

    /**
     * @brief Removes a ToDo from the list by its name.
     *
     * @param todo Name of the ToDo to be removed.
     */
    void removeItem(const std::string& todo);

    /**
     * @brief Lists all ToDos in the ToDo list.
     *
     * @return A list of all ToDos.
     */
    std::vector<std::string> showList() const;
private:
    std::vector<std::string> todo_list; ///< Vector that holds the list of ToDos.
};

#endif /* _TODO_H */