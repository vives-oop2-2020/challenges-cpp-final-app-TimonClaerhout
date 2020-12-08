#include "wall.h"

Wall::Wall(int x, int y) {
    _x = x;
    _y = y;
}

int Wall::x(){
    return _x;
}

int Wall::y(void){
    return _y;
}

void Wall::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), '#');
}
