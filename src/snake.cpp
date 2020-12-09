#include "snake.h"

Snake::Snake(int x, int y)
  : Entity(x, y){
}

void Snake::render(Canvas * canvas){
    canvas->draw_symbol(x(), y(), 'O');
}

void Snake::update(void) {
    int x = 0;
    int y = 0;
  next_position(&x,&y);
  Entity::move(x,y);
}

void Snake::next_position(int * x, int * y) {
  *x = this->x();
  *y = this->y();
  switch(direction) {
    case Direction::LEFT: *x = this->x() - speed; break;
    case Direction::RIGHT: *x = this->x() + speed; break;
    case Direction::UP: *y = this->y() - speed; break;
    case Direction::DOWN: *y = this->y() + speed; break;
  }
}

void Snake::down(void) {
  move(Direction::DOWN);
}

void Snake::up(void) {
  move(Direction::UP);
}

void Snake::left(void) {
  move(Direction::LEFT);
}

void Snake::right(void) {
  move(Direction::RIGHT);
}

void Snake::move(Direction direction) {
  this->direction = direction;
  speed = 1;
}