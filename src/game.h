#pragma once

#include <vector>
#include "wall.h"
#include "fruit.h"
#include "snake.h"
#include "controller.h"
#include "canvas.h"

class Game {

  public:
    Game(void);

  private:
    void create_walls(void);
    void create_fruits(void);

  private:
    void render(void);
    void update(void);

  private:
    void process_keyboard_input(void);

  private:
    Snake snake;
    std::vector<Wall> walls;
    std::vector<Fruit> fruits;
    Canvas canvas;

    const static int WIDTH = 30;
    const static int HEIGHT = 10;

};