#pragma once
#include "canvas.h"
#include "entity.h"

class Tail : public Entity {

  public:
    Tail(int x, int y);

  public:
    void render(Canvas * canvas);

};