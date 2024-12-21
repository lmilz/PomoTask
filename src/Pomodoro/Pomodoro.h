#ifndef _POMODORO_H
#define _POMODORO_H

// Includes
#include <iostream>
#include <chrono>
#include <thread>

class Pomodoro {
public:
    /**
     * @brief Constructor.
     * 
     * @param focustime Focus time for pomodoro timer.
     * @param breaktime Break time for pomodoro timer.
     */
    Pomodoro(int focustime, int breaktime);

    /**
     * @brief Start the pomodoro timer.
     */
    bool start();

    /**
     * @brief Setter function for focus time.
     *
     * @param new_focustime New value of time focus time.
     */
    void setFocusTime(const int new_focustime);

    /**
     * @brief Getter function for focus time.
     *
     * @return Focus time of the pomodoro timer.
     */    
    int getFocusTime() const;
private:
    int focustime;
    int breaktime;
};

#endif /* _POMODORO_H */