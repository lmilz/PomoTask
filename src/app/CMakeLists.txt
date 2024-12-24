add_library(app
    src/PomoTaskApp.cpp
)

target_include_directories(app PUBLIC include)
target_link_libraries(app PRIVATE ToDo Pomodoro)

add_executable(main src/main.cpp)

target_include_directories(main PUBLIC ../Pomodoro/include)
target_include_directories(main PUBLIC ../ToDo/include)

target_link_libraries(main PRIVATE app)
