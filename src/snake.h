#pragma once


#include "canvas.h"

// struct Location {
//   int x;
//   int y;
// }

class PacMan {

  private:
    enum class Direction {
      UP, LEFT, RIGHT, DOWN
    };

  public:
    Snake(int x, int y);

  public:
    void render(Canvas * canvas);
    void update(void);

  public:
    void stop(void);
    void down(void);
    void up(void);
    void left(void);
    void right(void);

  private:
    void move(Direction direction);

  private:
    int speed = 1;
    Direction direction = Direction::LEFT;
};