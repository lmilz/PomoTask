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

#ifndef POMOTASK_EFFECT_H
#define POMOTASK_EFFECT_H

class Effect
{
   public:
    Effect(int rows, int cols, int color);
    virtual ~Effect() = default;

    virtual void Run() = 0;

    void SetRows(int new_rows);
    int GetRows() const;
    void SetCols(int new_cols);
    int GetCols() const;
    void SetColor(int new_color);
    int GetColor() const;

   protected:
    int rows;
    int cols;
    int color;

    void SetCursorPosition(int row, int col);
    void SetTextColor();
    void ClearScreen();
};

#endif /* POMOTASK_EFFECT_H */