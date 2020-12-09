#pragma once
#include "entity.h"
#include "canvas.h"

class Snake : public Entity {

  public:
    Snake(int x, int y);

  public:
    void render(Canvas * canvas);
    void update(void);
    void next_position(int * x, int * y);

  public:
    void stop(void);
    void down(void);
    void up(void);
    void left(void);
    void right(void);

  private:
    enum class Direction {
      UP, LEFT, RIGHT, DOWN
    };
  private:
    void move(Direction direction);

  private:
    int speed = 1;
    Direction direction = Direction::LEFT;

};