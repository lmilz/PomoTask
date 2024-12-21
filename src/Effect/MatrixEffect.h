#ifndef _MATRIXEFFECT_H
#define _MATRIXEFFECT_H

// Includes
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Effect.h"

class MatrixEffect : public Effect {
 public:
  MatrixEffect(int rows, int cols, int color = 32);

  void run() override;

 private:
  std::vector<char> columns;
};

#endif /* _MATRIXEFFECT_H */