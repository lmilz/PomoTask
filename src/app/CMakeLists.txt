add_library(app
    src/main.cpp
    src/PomoTaskApp.cpp
)

target_include_directories(app PUBLIC include)
target_link_libraries(app PRIVATE ToDo Pomodoro)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE app)