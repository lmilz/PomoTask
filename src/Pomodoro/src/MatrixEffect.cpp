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

// Includes
#include "MatrixEffect.h"

#include <cstdlib>
#include <iostream>
#include <random>

#include "Effect.h"

MatrixEffect::MatrixEffect(int rows, int cols, int color)
    : Effect(rows, cols, color),
      columns(cols, ' '),
      gen(std::random_device{}()),
      dist_char(33, 126),
      dist_chance(0, 9),
      dist_row(1, rows)
{
}

void MatrixEffect::Run()
{
    SetTextColor();
    int i = 0;

    for (auto iter = columns.begin(); iter != columns.end(); ++iter, ++i) {
        // 30% Chance, einen neuen Charakter zu generieren
        if (dist_chance(gen) < 2) {
            // Generiere ein zufälliges druckbares ASCII-Zeichen
            *iter = static_cast<char>(dist_char(gen));
        }
        else {
            *iter = ' ';
        }

        // Bewege den Cursor zu einer zufälligen Position in der aktuellen Spalte
        SetCursorPosition(dist_row(gen), i + 1);
        std::cout << *iter;
    }
    std::cout.flush();
}