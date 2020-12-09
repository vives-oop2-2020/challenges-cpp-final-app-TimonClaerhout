#include "wall.h"
#include "entity.h"

Wall::Wall(int x, int y)
: Entity(x,y) {
}

void Wall::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), '#');
}
