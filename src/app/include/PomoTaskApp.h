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

#ifndef POMOTASK_APP_H
#define POMOTASK_APP_H

// Includes

#include <atomic>
#include <string>
#include <span>

#include "Effect.h"
#include "Pomodoro.h"
#include "ToDoList.h"

class PomoTaskApp
{
   public:
    PomoTaskApp(std::span<char*> args);
    virtual ~PomoTaskApp();
    void Execute();

   private:
    ToDoList* todo_list;
    Pomodoro* pomodoro_timer;
    std::unique_ptr<Effect> effect;
    std::string command;
    std::vector<std::string> argument_list;
    std::atomic<bool> running_app;

    std::pair<int, int> GetTerminalSize();
    void PrintHelp();
    void InitEffect();
    void InitPomodoroTimer();
    void RunPomodoroTimer();
    void RunEffect();
    void AddTodo(std::string& todo);
    void RemoveToDo(std::string& todo);
    void ShowToDo();
};

#endif /* POMOTASK_APP_H */