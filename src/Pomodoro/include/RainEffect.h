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

#ifndef POMOTASK_RAINEFFECT_H
#define POMOTASK_RAINEFFECT_H

// Includes
#include <random>
#include <vector>

#include "Effect.h"

class RainEffect : public Effect
{
   public:
    RainEffect(int rows, int cols, int color = 34);

    void Run() override;

   private:
    struct Raindrop {
        int x;
        int y;
    };

    std::vector<Raindrop> raindrops;
    std::vector<char> waterfilm;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist_chance;
    std::uniform_int_distribution<int> dist_cols;
};

#endif /* POMOTASK_RAINEFFECT_H */