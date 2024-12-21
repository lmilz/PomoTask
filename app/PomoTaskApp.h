#ifndef _POMOTASKAPP_H
#define _POMOTASKAPP_H

// Includes
#include <sys/ioctl.h>
#include <unistd.h>
#include <atomic>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include "Effect.h"
#include "MatrixEffect.h"
#include "Pomodoro.h"
#include "RainEffect.h"
#include "ToDo.h"

class PomoTaskApp {
 public:
  PomoTaskApp(int argc, char* argv[]);
  virtual ~PomoTaskApp();
  void execute();

 private:
  ToDo* todo_list;
  Pomodoro* pomodoro_timer;
  std::unique_ptr<Effect> effect;
  std::string command;
  std::vector<std::string> argument_list;
  std::atomic<bool> running_app;

  std::pair<int, int> getTerminalSize();
  void printHelp();
  void initCommand(int argc, char* argv[]);
  void initEffect();
  void initPomodoroTimer();
  void RunPomodoroTimer();
  void RunEffect();
  void addTodo(std::string& todo);
  void removeToDo(std::string& todo);
  void showToDo();
};

#endif /* _POMOTASKAPP_H */