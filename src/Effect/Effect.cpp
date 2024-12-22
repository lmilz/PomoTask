#include "Effect.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

Effect::Effect(int rows, int cols, int color)
    : rows(rows), cols(cols), color(color) {
  srand(time(0));  // Initialize random number generator
  clearScreen();
}

void Effect::setCursorPosition(int row, int col) {
  std::cout << "\033[" << row << ";" << col << "H";
}

void Effect::setTextColor() { std::cout << "\033[1;" << color << "m"; }

void Effect::clearScreen() { std::cout << "\033[2J\033[H"; }

void Effect::setRows(const int new_rows) { rows = new_rows; }

int Effect::getRows() const { return rows; }

void Effect::setCols(const int new_cols) { cols = new_cols; }

int Effect::getCols() const { return cols; }

void Effect::setColor(const int new_color) { color = new_color; }

int Effect::getColor() const { return color; }