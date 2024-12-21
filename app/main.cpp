#include "PomoTaskApp.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Verwenden Sie --help für eine Liste der Befehle.\n";
    return 0;
  }

  PomoTaskApp* app = new PomoTaskApp(argc, argv);

  app->execute();

  delete app;
  return 0;
}
