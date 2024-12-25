# Pomodoro lib
add_library(Pomodoro
    src/Pomodoro.cpp
    src/Effect.cpp
    src/MatrixEffect.cpp
    src/RainEffect.cpp
)

target_include_directories(Pomodoro PUBLIC include)

# google test
add_executable(test_pomodoro
    tests/UnitTest_Effect.cpp
    tests/UnitTest_Pomodoro.cpp
)

target_link_libraries(test_pomodoro PRIVATE Pomodoro GTest::GTest GTest::Main)

enable_testing()
add_test(NAME PomodoroTests COMMAND test_pomodoro)