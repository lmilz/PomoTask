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
#include "CLICommand.h"

#include <cstddef>
#include <span>
#include <stdexcept>
#include <vector>

CLICommand::CLICommand(std::span<char*> args)
{
    // interprete command
    if (args.size() > 1) {
        command = args[1];

        if (command == "--help" || command == "-h") {
            command_type = CommandType::POMOTASK_APP_HELP;
        }
        else if (command == "--pomodoro" || command == "-p") {
            command_type = CommandType::POMOTASK_APP_POMODORO;
        }
        else if (command == "--show" || command == "-s") {
            command_type = CommandType::POMOTASK_APP_SHOW_TODOLIST;
        }
        else if (command == "--add" || command == "-a") {
            command_type = CommandType::POMOTASK_APP_ADD_TODO;
        }
        else if (command == "--update" || command == "-u") {
            command_type = CommandType::POMOTASK_APP_UPDATE_TODO;
        }
        else {
            throw std::invalid_argument("Unknown command");
        }

        for (size_t index = 2; index < args.size(); ++index) {
            argument_list.emplace_back(args[index]);
        }
    }
    else {
        command_type = CommandType::POMOTASK_APP_HELP;
    }
}

CommandType CLICommand::GetCommand() const
{
    return command_type;
}

std::vector<std::string> CLICommand::GetArgumentList() const
{
    return argument_list;
}