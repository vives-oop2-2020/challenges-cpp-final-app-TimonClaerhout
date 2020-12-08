#pragma once

#include <vector>
#include "wall.h"
#include "canvas.h"
#include "snake.h"
#include "controller.h"

class Game {

  public:
    Game(void);

  private:
    void create_walls(void);

  private:
    void render(void);
    void update(void);

  private:
    Snake snake;
    std::vector<Wall> walls;

    Canvas canvas;

    const static int WIDTH = 30;
    const static int HEIGHT = 10;

};