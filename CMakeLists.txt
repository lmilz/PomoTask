cmake_minimum_required(VERSION 3.16)
project(PomoTask)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# google test
find_package(GTest REQUIRED)

enable_testing()

add_subdirectory(src/app)
add_subdirectory(src/ToDo)
add_subdirectory(src/Pomodoro)