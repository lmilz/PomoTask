#ifndef _SHELLFX_RAINEFFECT_H
#define _SHELLFX_RAINEFFECT_H

// Includes
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Effect.h"

/**
 * @brief Class for simulating a rain effect in the terminal.
 * 
 * The `RainEffect` class generates raindrop-like visual effects. Drops fall vertically 
 * and disappear once they reach the bottom of the screen.
 */
class RainEffect : public Effect {
private:
    /**
     * @brief Represents a single raindrop.
     */
    struct Raindrop {
        int x; ///< Current column position of the raindrop.
        int y; ///< Current row position of the raindrop.
    };

    std::vector<Raindrop> raindrops; ///< Stores active raindrops.
    std::vector<char>     waterfilm; ///< Stores water film

public:
    /**
     * @brief Constructs a RainEffect instance.
     * 
     * @param rows Number of rows in the terminal.
     * @param cols Number of columns in the terminal.
     * @param color ANSI color code for the effect (default: blue, code 34).
     */
    RainEffect(int rows, int cols, int color = 34);

    /**
     * @brief Executes the rain effect.
     */
    void run() override;
};


#endif /* _SHELLFX_RAINEFFECT_H */