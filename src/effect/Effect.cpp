#include "Effect.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

// Constructs an `Effect` instance with specified dimensions and color.
Effect::Effect(int rows, int cols, int color) : rows(rows), cols(cols), color(color) {
  srand(time(0));  // Initialize random number generator
  clearScreen();
}

// Sets the cursor position in the terminal.
void Effect::setCursorPosition(int row, int col) {
  std::cout << "\033[" << row << ";" << col << "H";
}

// Sets the text color in the terminal.
void Effect::setTextColor() { std::cout << "\033[1;" << color << "m"; }

// Clears the terminal screen.
void Effect::clearScreen() { std::cout << "\033[2J\033[H"; }

// Setter function for row value
void Effect::setRows(const int new_rows) { rows = new_rows; }

// Getter function for row value
int Effect::getRows() const { return rows; }

// Setter function for col value
void Effect::setCols(const int new_cols) { cols = new_cols; }

// Getter function for col value
int Effect::getCols() const { return cols; }

// Setter function for color value
void Effect::setColor(const int new_color) { color = new_color; }

// Getter function for color value
int Effect::getColor() const { return color; }