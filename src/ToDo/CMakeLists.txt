add_library(ToDo
    src/ToDoList.cpp
    src/Database.cpp
)

target_include_directories(ToDo PUBLIC include)
target_link_libraries(ToDo PRIVATE sqlite3)