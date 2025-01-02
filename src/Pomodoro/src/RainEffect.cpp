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

//Includes
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Effect.h"
#include "RainEffect.h"

RainEffect::RainEffect(int rows, int cols, int color)
    : Effect(rows, cols, color), waterfilm(cols, ' '), gen(std::random_device{}()), dist_chance(0, 9), dist_cols(0, cols - 1)
{
}

void RainEffect::Run()
{
        SetTextColor();

        // 30% Wahrscheinlichkeit, einen neuen Regentropfen hinzuzufügen
        if (dist_chance(gen) < 3) {
            raindrops.push_back({dist_cols(gen), 0}); // Neuer Tropfen in zufälliger Spalte
        }

        // Verschiebe bestehende Regentropfen nach unten und lösche ihre alten Positionen
        for (auto& drop : raindrops) {
            SetCursorPosition(drop.y, drop.x + 1);
            std::cout << " "; // Löschen der alten Position
            drop.y++;
        }

        // Zeichne die Regentropfen an ihren neuen Positionen
        for (const auto& drop : raindrops) {
            if (drop.y < GetRows()) {
                SetCursorPosition(drop.y, drop.x + 1);
                std::cout << "|"; // Neuer Regentropfen
            } else {
                waterfilm[drop.x] = '.'; // Tropfen erreicht den Boden
            }
        }

        // Entferne Regentropfen, die den Boden erreicht haben
        raindrops.erase(
            std::remove_if(raindrops.begin(),
                           raindrops.end(),
                           [this](const Raindrop& drop) { return drop.y >= GetRows(); }),
            raindrops.end());

        // Zeichne den Wasserfilm
        for (int i = 0; i < GetCols(); ++i) {
            if (waterfilm[i] != ' ') {
                SetCursorPosition(GetRows(), i + 1);
                std::cout << waterfilm[i];
            }
        }

        std::cout.flush();
}
