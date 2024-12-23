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

#include "RainEffect.h"

RainEffect::RainEffect(int rows, int cols, int color)
    : Effect(rows, cols, color), waterfilm(cols, ' ')
{
}

void RainEffect::run()
{
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
        }
        else {
            waterfilm[drop.x] = '.';
        }
    }

    // Remove raindrops that have reached the bottom of the screen
    raindrops.erase(std::remove_if(raindrops.begin(),
                                   raindrops.end(),
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
