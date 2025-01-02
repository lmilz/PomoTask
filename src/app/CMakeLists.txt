add_library(App
    src/PomoTaskApp.cpp
    src/CLICommand.cpp
)

target_include_directories(App PUBLIC include)
target_link_libraries(App PRIVATE ToDo Pomodoro)

add_executable(PomoTask src/main.cpp)

target_include_directories(PomoTask PUBLIC ../Pomodoro/include)
target_include_directories(PomoTask PUBLIC ../ToDo/include)

target_link_libraries(PomoTask PRIVATE App)

# google test
add_executable(test_app
    tests/UnitTest_CLICommand.cpp
)

target_link_libraries(test_app PRIVATE App GTest::GTest GTest::Main)

enable_testing()
add_test(NAME AppTests COMMAND test_app)