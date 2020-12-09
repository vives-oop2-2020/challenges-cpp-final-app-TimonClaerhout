#pragma once
#include "canvas.h"
#include "entity.h"

class Wall : public Entity {

  public:
    Wall(int x, int y);

  public:
    void render(Canvas * canvas);

};