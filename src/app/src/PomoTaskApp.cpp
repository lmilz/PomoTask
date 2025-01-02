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
#include <sys/ioctl.h>
#include <unistd.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <span>
#include <string>
#include <thread>
#include <utility>

#include "PomoTaskApp.h"
#include "MatrixEffect.h"
#include "Pomodoro.h"
#include "RainEffect.h"
#include "ToDo.h"
#include "ToDoList.h"

PomoTaskApp::PomoTaskApp(std::span<char*> args) : running_app(true)
{
    todo_list = new ToDoList();
    pomodoro_timer = new Pomodoro(0);

    // interprete command
    if (args.size() > 1) {
        command = args[1];

        for (size_t index = 2; index < args.size(); ++index) {
            argument_list.emplace_back(args[index]);
        }
    }
}

PomoTaskApp::~PomoTaskApp()
{
    running_app = false;

    delete todo_list;
    delete pomodoro_timer;
}

void PomoTaskApp::Execute()
{
    if (command == "--help") {
        PrintHelp();
    }
    else if (command == "--pomodoro") {
        InitPomodoroTimer();
        InitEffect();

        std::thread timer_thread(&PomoTaskApp::RunPomodoroTimer, this);
        std::thread effect_thread(&PomoTaskApp::RunEffect, this);

        timer_thread.join();
        effect_thread.join();
    }
    else if (command == "--add") {
        const ToDoDTO dto = {.name = argument_list[0],
                             .description = argument_list[1],
                             .status = "Backlog",
                             .due_date = argument_list[2]};
        todo_list->AddItem(ToDo::FromDTO(dto));
    }
    else if (command == "--show") {
        for (const auto& item : todo_list->ShowList()) {
            auto dto = item.ToDTO();
            std::cout << "- " << dto.name << ": " << dto.description
                      << " with status: " << dto.status << " and due date: " << dto.due_date
                      << "\n";
        }
    }
    else {
        std::cout << "Unbekannter Befehl: " << command << "\n";
        std::cout << "Verwenden Sie --help für eine Liste der Befehle.\n";
    }
}

std::pair<int, int> PomoTaskApp::GetTerminalSize()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_row, w.ws_col};
}

void PomoTaskApp::PrintHelp()
{
    // Liste der Befehle und Beschreibungen
    const std::map<std::string, std::string> commands
        = {{"--help                          ", "Zeigt diese Hilfeseite an."},
           {"--pomodoro <focus time> <effect>",
            "Pomodoro Timer mit der Fokuszeit und den CLI Effekt."},
           {"--add <Name> <Description> <Due Date>",
            "Neuer ToDo mit Namen, Beschreibung und Fertigungsdatum."},
           {"--show", "Alle ToDos anzeigen."}};

    std::cout << "Verfügbare Befehle:\n";
    for (const auto& [command, description] : commands) {
        std::cout << "  " << command << "\t" << description << "\n";
    }
}

void PomoTaskApp::InitEffect()
{
    auto [rows, cols] = GetTerminalSize();
    if (argument_list[1] == "Matrix") {
        effect = std::make_unique<MatrixEffect>(rows + 2, cols);
    }
    else if (argument_list[1] == "Rain") {
        effect = std::make_unique<RainEffect>(rows + 2, cols);
    }
    else {
        std::cout << "Ungültige Auswahl!\n";
    }
}

void PomoTaskApp::InitPomodoroTimer()
{
    if (std::stoi(argument_list[0]) <= 0) {
        std::cerr << "Bitte eine gültige Fokuszeit eingeben." << "\n";
        return;
    }

    pomodoro_timer->SetFocusTime(std::stoi(argument_list[0]));
}

void PomoTaskApp::RunEffect()
{
    while (running_app) {
        effect->Run();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void PomoTaskApp::RunPomodoroTimer()
{
    while (running_app) {
        if (!pomodoro_timer->Start()) {
            running_app = false;
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}