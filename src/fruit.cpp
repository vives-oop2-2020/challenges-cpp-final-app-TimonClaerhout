#include "fruit.h"

Fruit::Fruit(int x, int y)
  : Entity(x, y) {
}

void Fruit::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), 'x');
}