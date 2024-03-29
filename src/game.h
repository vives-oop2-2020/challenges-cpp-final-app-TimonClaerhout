#pragma once

#include <vector>
#include "wall.h"
#include "fruit.h"
#include "snake.h"
#include "controller.h"
#include "canvas.h"
#include "scoreboard.h"
#include "menu.h"
#include <iostream>

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

  private:
    void process_keyboard_input(void);
    void game_loop(void);
    void change_speed(void);
    void go_to_menu(void);

  private:
    Snake snake;
    std::vector<Wall> walls;
    std::vector<Fruit> fruits;
    std::vector<Snake> snakes;
    Canvas canvas;
    Scoreboard scoreboard;

    int WIDTH = 30;
    int HEIGHT = 10;

    bool gameOver = false;

    int delay = 100'000;
};