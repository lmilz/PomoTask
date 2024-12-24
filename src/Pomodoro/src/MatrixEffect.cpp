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