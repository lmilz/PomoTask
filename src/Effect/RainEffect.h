#ifndef _RAINEFFECT_H
#define _RAINEFFECT_H

// Includes
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Effect.h"

class RainEffect : public Effect {
 public:
  RainEffect(int rows, int cols, int color = 34);

  void run() override;

 private:
  struct Raindrop {
    int x;
    int y;
  };

  std::vector<Raindrop> raindrops;
  std::vector<char> waterfilm;
};

#endif /* _AINEFFECT_H */