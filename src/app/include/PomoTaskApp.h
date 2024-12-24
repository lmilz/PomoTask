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

#ifndef _POMOTASKAPP_H
#define _POMOTASKAPP_H

// Includes
#include <sys/ioctl.h>
#include <unistd.h>

#include <atomic>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <thread>

#include "Effect.h"
#include "MatrixEffect.h"
#include "Pomodoro.h"
#include "RainEffect.h"
#include "ToDo.h"

class PomoTaskApp
{
   public:
    PomoTaskApp(int argc, char* argv[]);
    virtual ~PomoTaskApp();
    void execute();

   private:
    ToDo* todo_list;
    Pomodoro* pomodoro_timer;
    std::unique_ptr<Effect> effect;
    std::string command;
    std::vector<std::string> argument_list;
    std::atomic<bool> running_app;

    std::pair<int, int> getTerminalSize();
    void printHelp();
    void initCommand(int argc, char* argv[]);
    void initEffect();
    void initPomodoroTimer();
    void RunPomodoroTimer();
    void RunEffect();
    void addTodo(std::string& todo);
    void removeToDo(std::string& todo);
    void showToDo();
};

#endif /* _POMOTASKAPP_H */