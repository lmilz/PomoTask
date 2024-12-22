#include "Pomodoro.h"

Pomodoro::Pomodoro(int focustime, int breaktime)
    : focustime(focustime * 60), breaktime(breaktime) {}

bool Pomodoro::start() {
  std::cout << "\033[1;1H";  // Cursor nach oben links setzen
  std::cout << "\rVerbleibende Zeit: " << focustime / 60 << " Minuten "
            << focustime % 60 << " Sekunden" << std::flush;
  --focustime;

  if (focustime == 0) {
    std::cout << std::endl
              << "Pomodoro beendet! Zeit für eine Pause!" << std::endl;
    return false;
  }

  return true;
}

void Pomodoro::setFocusTime(const int new_focustime) {
  focustime = new_focustime * 60;
}

int Pomodoro::getFocusTime() const { return focustime; }