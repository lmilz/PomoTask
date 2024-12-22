#include "MatrixEffect.h"

MatrixEffect::MatrixEffect(int rows, int cols, int color)
    : Effect(rows, cols, color), columns(cols, ' ') {}

void MatrixEffect::run() {
  setTextColor();
  int i = 0;
  for (auto iter = columns.begin(); iter != columns.end(); ++iter, ++i) {
    if (rand() % 10 < 2) {
      // Generate a random printable ASCII character
      *iter = rand() % 94 + 33;
    } else {
      *iter = ' ';
    }
    // Move cursor to a random position in the current column
    setCursorPosition(rand() % rows + 1, i + 1);
    std::cout << *iter;
  }
  std::cout.flush();
}