#include "Pomodoro.h"

// Constructor
Pomodoro::Pomodoro(int focustime, int breaktime)
    : focustime(focustime * 60), breaktime(breaktime) {}

// Function for start the pomodoro timer
bool Pomodoro::start() {
  // std::cout << "Pomodoro gestartet für " << focustime << " Minuten." << std::endl;
  std::cout << "\033[1;1H";  // Cursor nach oben links setzen
  std::cout << "\rVerbleibende Zeit: " << focustime / 60 << " Minuten " << focustime % 60
            << " Sekunden" << std::flush;
  --focustime;

  if (focustime == 0) {
    std::cout << std::endl << "Pomodoro beendet! Zeit für eine Pause!" << std::endl;
    return false;
  }

  return true;
}

// Setter function for focus time
void Pomodoro::setFocusTime(const int new_focustime) { focustime = new_focustime * 60; }

// Getter function for focus time
int Pomodoro::getFocusTime() const { return focustime; }