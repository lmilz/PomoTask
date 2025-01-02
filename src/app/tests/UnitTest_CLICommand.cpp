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

#include <gtest/gtest.h>
#include <array>
#include <stdexcept>
#include <span>
#include <string>
#include <vector>

#include "CLICommand.h" 

TEST(CLICommandTest, CommandPomodoro) {
    const std::array<std::string, 4> args1 = {"program", "--pomodoro", "arg1", "arg2"};
    // Create a vector of char* and populate it using c_str()
    std::vector<char*> argv1;
    argv1.reserve(args1.size()); 
    for (const auto& arg : args1) {
        argv1.push_back(const_cast<char*>(arg.c_str()));
    }

    const std::span<char*> cli1(argv1.data(), argv1.size());
    const CLICommand cmd1(cli1); 
    EXPECT_EQ(cmd1.GetCommand(), CommandType::POMOTASK_APP_POMODORO);
    EXPECT_EQ(cmd1.GetArgumentList().size(), 2);
    EXPECT_EQ(cmd1.GetArgumentList()[0], "arg1");
    EXPECT_EQ(cmd1.GetArgumentList()[1], "arg2");
}

TEST(CLICommandTest, CommandHelp) {
    const std::array<std::string, 2> args2 = {"program", "--help"};
    // Create a vector of char* and populate it using c_str()
    std::vector<char*> argv2;
    argv2.reserve(args2.size()); 
    for (const auto& arg : args2) {
        argv2.push_back(const_cast<char*>(arg.c_str()));
    }

    const std::span<char*> cli2(argv2.data(), argv2.size());
    const CLICommand cmd2(cli2);
    EXPECT_EQ(cmd2.GetCommand(), CommandType::POMOTASK_APP_HELP);
    EXPECT_TRUE(cmd2.GetArgumentList().empty());
}

TEST(CLICommandTest, CommandIsSetWrongly) {
    const std::array<std::string, 2> args3 = {"program", "unknown_command"};
    // Create a vector of char* and populate it using c_str()
    std::vector<char*> argv3;
    argv3.reserve(args3.size()); 
    for (const auto& arg : args3) {
        argv3.push_back(const_cast<char*>(arg.c_str()));
    }

    const std::span<char*> cli3(argv3.data(), argv3.size());
    EXPECT_THROW(const CLICommand cmd3(cli3), std::invalid_argument);
}