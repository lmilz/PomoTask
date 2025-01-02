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
#include <cstdint>
#include <span>
#include <string>
#include <vector>

enum CommandType : std::uint8_t
{
    POMOTASK_APP_HELP = 0,
    POMOTASK_APP_POMODORO = 1,
    POMOTASK_APP_SHOW_TODOLIST = 2,
    POMOTASK_APP_ADD_TODO = 3,
    POMOTASK_APP_UPDATE_TODO = 4
};

class CLICommand
{
   public:
    CLICommand(std::span<char*> args);

    CommandType GetCommand() const;
    std::vector<std::string> GetArgumentList() const;

   private:
    std::string command;
    CommandType command_type;
    std::vector<std::string> argument_list;
};