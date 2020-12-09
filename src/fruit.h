#pragma once

#include "canvas.h"
#include "entity.h"

class Fruit : public Entity  {

  public:
    Fruit(int x, int y);

  public:
    void render(Canvas * canvas);
};