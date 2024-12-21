#ifndef _POMODORO_H
#define _POMODORO_H

// Includes
#include <chrono>
#include <iostream>
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