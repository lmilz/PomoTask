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

#include "Effect.h"

// Mock implementation for testing terminal-specific methods
class MockEffect : public Effect
{
   public:
    MockEffect(int rows, int cols, int color) : Effect(rows, cols, color) {}
    void run() override {}

    // Expose protected methods for testing
    void testSetCursorPosition(int row, int col) { setCursorPosition(row, col); }

    void testSetTextColor() { setTextColor(); }

    void testClearScreen() { clearScreen(); }
};

TEST(EffectTests, ConstructorInitializesValues)
{
    MockEffect* effect = new MockEffect(10, 20, 30);
    EXPECT_EQ(10, effect->getRows());
    EXPECT_EQ(20, effect->getCols());
    EXPECT_EQ(30, effect->getColor());
    delete effect;
}

TEST(EffectTests, Setter_Getter_Rows)
{
    MockEffect* effect = new MockEffect(10, 20, 30);
    effect->setRows(40);
    EXPECT_EQ(40, effect->getRows());
    delete effect;
}

TEST(EffectTests, Setter_Getter_Cols)
{
    MockEffect* effect = new MockEffect(10, 20, 30);
    effect->setCols(50);
    EXPECT_EQ(50, effect->getCols());
    delete effect;
}

TEST(EffectTests, Setter_Getter_Color)
{
    MockEffect* effect = new MockEffect(10, 20, 30);
    effect->setColor(60);
    EXPECT_EQ(60, effect->getColor());
    delete effect;
}