#include "snake.h"
#include "json.hpp"
#include <fstream>

using namespace nlohmann;
  
Snake::Snake(int x, int y)
  : Entity(x, y){
}

void Snake::render(Canvas * canvas){
  std::ifstream ifs("symbol.json");
  json jf = json::parse(ifs);
  auto symbolfile =  jf["snake"].get<std::string>();
  char symbol = symbolfile[0];
  canvas->draw_symbol(x(), y(), symbol);
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