#ifndef _EFFECT_H
#define _EFFECT_H

class Effect {
public:
    Effect(int rows, int cols, int color);
    virtual ~Effect() = default;

    virtual void run() = 0;
    
    void setRows(const int new_rows);
    int getRows() const;
    void setCols(int new_cols);
    int getCols() const;
    void setColor(int new_color);
    int getColor() const;

protected:
    int rows;
    int cols;
    int color;

    void setCursorPosition(int row, int col);
    void setTextColor();
    void clearScreen();
};

#endif /* _EFFECT_H */