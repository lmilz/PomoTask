add_library(Pomodoro
    src/Pomodoro.cpp
    src/Effect.cpp
    src/MatrixEffect.cpp
    src/RainEffect.cpp
)

target_include_directories(Pomodoro PUBLIC include)