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

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
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

// Test group for the BaseEffect class
TEST_GROUP(EffectTests)
{
    MockEffect* effect;

    void setup()
    {
        effect = new MockEffect(10, 20, 30);
    }

    void teardown()
    {
        delete effect;
    }
};

TEST(EffectTests, ConstructorInitializesValues)
{
    CHECK_EQUAL(10, effect->getRows());
    CHECK_EQUAL(20, effect->getCols());
    CHECK_EQUAL(30, effect->getColor());
}

TEST(EffectTests, Setter_Getter_Rows)
{
    effect->setRows(40);
    CHECK_EQUAL(40, effect->getRows());
}

TEST(EffectTests, Setter_Getter_Cols)
{
    effect->setCols(50);
    CHECK_EQUAL(50, effect->getCols());
}

TEST(EffectTests, Setter_Getter_Color)
{
    effect->setColor(60);
    CHECK_EQUAL(60, effect->getColor());
}