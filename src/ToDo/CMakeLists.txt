# todo lib
add_library(ToDo
    src/ToDoList.cpp
    src/Database.cpp
)

target_include_directories(ToDo PUBLIC include)
target_link_libraries(ToDo PRIVATE sqlite3)

# google test
add_executable(test_todo
    tests/UnitTest_ToDo.cpp
    tests/UnitTest_Database.cpp
    tests/UnitTest_Schema.cpp
)

target_link_libraries(test_todo PRIVATE ToDo GTest::GTest GTest::Main)

enable_testing()
add_test(NAME ToDoTests COMMAND test_todo)