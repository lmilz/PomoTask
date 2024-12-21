#ifndef _POMODORO_H
#define _POMODORO_H

// Includes
#include <iostream>
#include <chrono>
#include <thread>

class Pomodoro {
public:
    Pomodoro(int focustime, int breaktime);

    bool start();
    void setFocusTime(const int new_focustime); 
    int getFocusTime() const;
private:
    int focustime;
    int breaktime;
};

#endif /* _POMODORO_H */