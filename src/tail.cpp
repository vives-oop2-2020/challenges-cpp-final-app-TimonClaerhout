#include "tail.h"

Tail::Tail(int x, int y)
: Entity(x,y) {
    //x() = x;
    //y() = y;
}

void Tail::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), 'o');
}
