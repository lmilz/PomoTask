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
#include "Pomodoro.h"

#include <iostream>

Pomodoro::Pomodoro(int focus) : focustime(focus * 60)
{
}

bool Pomodoro::Start()
{
    std::cout << "\033[1;1H";
    std::cout << "\rRemaining time: " << focustime / 60 << " min " << focustime % 60 << " sec"
              << std::flush;
    --focustime;

    if (focustime == 0) {
        std::cout << "\n"
                  << "Pomodoro finished! Time for a break!" << "\n";
        return false;
    }

    return true;
}

void Pomodoro::SetFocusTime(const int new_focustime)
{
    focustime = new_focustime * 60;
}