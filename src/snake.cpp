#include "snake.h"

Snake::Snake(int x, int y) {
    _x = x;
    _y = y;
}

int Snake::x(void){
    return _x;
}

int Snake::y(void){
    return _y;
}
