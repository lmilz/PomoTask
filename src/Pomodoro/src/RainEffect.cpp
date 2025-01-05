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
#include "RainEffect.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "Effect.h"

RainEffect::RainEffect(int rows, int cols, int color)
    : Effect(rows, cols, color),
      waterfilm(cols, ' '),
      gen(std::random_device{}()),
      dist_chance(0, 9),
      dist_cols(0, cols - 1)
{
}

void RainEffect::Run()
{
    SetTextColor();

    if (dist_chance(gen) < 3) {
        raindrops.push_back({dist_cols(gen), 0});
    }

    for (auto& drop : raindrops) {
        SetCursorPosition(drop.y, drop.x + 1);
        std::cout << " ";
        drop.y++;
    }

    for (const auto& drop : raindrops) {
        if (drop.y < GetRows()) {
            SetCursorPosition(drop.y, drop.x + 1);
            std::cout << "|";
        }
        else {
            waterfilm[drop.x] = '.';
        }
    }

    raindrops.erase(std::remove_if(raindrops.begin(),
                                   raindrops.end(),
                                   [this](const Raindrop& drop) { return drop.y >= GetRows(); }),
                    raindrops.end());

    for (int i = 0; i < GetCols(); ++i) {
        if (waterfilm[i] != ' ') {
            SetCursorPosition(GetRows(), i + 1);
            std::cout << waterfilm[i];
        }
    }

    std::cout.flush();
}
