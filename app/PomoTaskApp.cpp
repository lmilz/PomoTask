
#include "PomoTaskApp.h"

PomoTaskApp::PomoTaskApp(int argc, char* argv[]) : running_app(true) {
  todo_list = new ToDo();
  pomodoro_timer = new Pomodoro(0, 0);

  // interprete command
  if (argc > 1)
    command = argv[1];

  // save arguments for command
  for (int index = 2; index < argc; ++index) {
    argument_list.emplace_back(argv[index]);
  }
}

PomoTaskApp::~PomoTaskApp() {
  running_app = false;

  delete todo_list;
  delete pomodoro_timer;
}

void PomoTaskApp::execute() {
  if (command == "--help") {
    printHelp();
  } else if (command == "--pomodoro") {
    initPomodoroTimer();
    initEffect();

    std::thread timerThread(&PomoTaskApp::RunPomodoroTimer, this);
    std::thread effectThread(&PomoTaskApp::RunEffect, this);

    timerThread.join();
    effectThread.join();
  } else {
    std::cout << "Unbekannter Befehl: " << command << "\n";
    std::cout << "Verwenden Sie --help für eine Liste der Befehle.\n";
  }
}

std::pair<int, int> PomoTaskApp::getTerminalSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return {w.ws_row, w.ws_col};
}

void PomoTaskApp::printHelp() {
  // Liste der Befehle und Beschreibungen
  std::map<std::string, std::string> commands = {
      {"--help                          ", "Zeigt diese Hilfeseite an."},
      {"--pomodoro <focus time> <effect>", "Pomodoro Timer mit der Fokuszeit und den CLI Effekt."}};

  std::cout << "Verfügbare Befehle:\n";
  for (const auto& [command, description] : commands) {
    std::cout << "  " << command << "\t" << description << "\n";
  }
}

void PomoTaskApp::initEffect() {
  auto [rows, cols] = getTerminalSize();
  if (argument_list[1] == "Matrix") {
    effect = std::make_unique<MatrixEffect>(rows + 2, cols);
  } else if (argument_list[1] == "Rain") {
    effect = std::make_unique<RainEffect>(rows + 2, cols);
  } else {
    std::cout << "Ungültige Auswahl!\n";
  }
}

void PomoTaskApp::initPomodoroTimer() {
  if (std::stoi(argument_list[0]) <= 0) {
    std::cerr << "Bitte eine gültige Fokuszeit eingeben." << std::endl;
    return;
  }

  pomodoro_timer->setFocusTime(std::stoi(argument_list[0]));
}

void PomoTaskApp::RunEffect() {
  while (running_app) {
    effect->run();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void PomoTaskApp::RunPomodoroTimer() {
  while (running_app) {
    if (!pomodoro_timer->start()) {
      running_app = false;
      break;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}