// MIT License
//
// Copyright (c) 2024 Lars Milz
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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