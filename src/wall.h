#pragma once
#include "canvas.h"

class Wall {

  public:
    Wall(int x, int y);

  public:
    int x(void);
    int y(void);

  public:
    void render(Canvas * canvas);

  private:
  int _x = 0;
  int _y = 0;
};