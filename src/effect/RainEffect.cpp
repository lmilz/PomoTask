#include "RainEffect.h"

// Constructs an `RainEffect` instance with specified dimensions and color.
RainEffect::RainEffect(int rows, int cols, int color)
    : Effect(rows, cols, color), waterfilm(cols, ' ') {}

// Runs the rain effect.
void RainEffect::run() {
  setTextColor();

  // Randomly add new raindrops at the top of the screen
  if (rand() % 10 < 3) {
    raindrops.push_back({rand() % cols, 0});  // New raindrop at random column
  }

  // Move existing raindrops down and erase their previous positions
  for (auto& drop : raindrops) {
    setCursorPosition(drop.y, drop.x);
    std::cout << " ";  // Clear previous position
    drop.y++;          // Move raindrop down
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
  raindrops.erase(std::remove_if(raindrops.begin(), raindrops.end(),
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
