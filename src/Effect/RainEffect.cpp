#include "RainEffect.h"

RainEffect::RainEffect(int rows, int cols, int color)
    : Effect(rows, cols, color), waterfilm(cols, ' ') {}

void RainEffect::run() {
  setTextColor();

  if (rand() % 10 < 3) {
    raindrops.push_back({rand() % cols, 0});  // New raindrop at random column
  }

  // Move existing raindrops down and erase their previous positions
  for (auto& drop : raindrops) {
    setCursorPosition(drop.y, drop.x);
    std::cout << " "; 
    drop.y++;      
  }

  // Redraw raindrops in their new positions
  for (const auto& drop : raindrops) {
    if (drop.y < rows) {
      setCursorPosition(drop.y, drop.x);
      std::cout << "|";
    } else {
      waterfilm[drop.x] = '.';
    }
  }

  // Remove raindrops that have reached the bottom of the screen
  raindrops.erase(
      std::remove_if(raindrops.begin(), raindrops.end(),
                     [this](const Raindrop& drop) { return drop.y >= rows; }),
      raindrops.end());

  // Draw water film
  for (int i = 0; i < cols; ++i) {
    if (waterfilm[i] != ' ') {
      setCursorPosition(rows, i + 1);
      std::cout << waterfilm[i];
    }
  }

  std::cout.flush();
}
