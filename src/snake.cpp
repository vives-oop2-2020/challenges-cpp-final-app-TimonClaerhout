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

void Snake::render(Canvas * canvas){
    canvas->draw_symbol(x(), y(), 'O');
}

void Snake::update(void) {
    switch(direction) {
        case Direction::LEFT: _x -= speed; break;
        case Direction::RIGHT: _x += speed; break;
        case Direction::UP: _y -= speed; break;
        case Direction::DOWN: _y+= speed; break;
    }
}