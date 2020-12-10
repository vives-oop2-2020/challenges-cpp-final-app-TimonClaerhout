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
    void check_for_collisions_with_walls(void);
    void check_for_collisions_with_fruits(void);
    void check_for_collisions_with_tail(void);
    void process_keyboard_input(void);

  private:
    Snake snake;
    std::vector<Wall> walls;
    std::vector<Fruit> fruits;
    std::vector<Snake> snakes;
    Canvas canvas;

    const static int WIDTH = 30;
    const static int HEIGHT = 10;

    bool gameOver = false;
    int firstTail = 0;
};