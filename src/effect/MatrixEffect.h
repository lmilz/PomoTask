#ifndef _SHELLFX_MATRIXEFFECT_H
#define _SHELLFX_MATRIXEFFECT_H

// Includes
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Effect.h"

/**
 * @brief Class for simulating the Matrix rain effect.
 * 
 * The `MatrixEffect` class generates a visual effect resembling the iconic digital rain 
 * seen in the "Matrix" movies. Characters appear to fall vertically down the screen.
 */
class MatrixEffect : public Effect {
public:
    /**
     * @brief Constructs a MatrixEffect instance.
     * 
     * @param rows Number of rows in the terminal.
     * @param cols Number of columns in the terminal.
     * @param color ANSI color code for the effect (default: green, code 32).
     */
    MatrixEffect(int rows, int cols, int color = 32);

    /**
     * @brief Executes the Matrix rain effect.
     */
    void run() override;
private:
    std::vector<char> columns; ///< Stores the current characters for each column.

};

#endif /* _SHELLFX_MATRIXEFFECT_H */