#include "game.h"
#include <unistd.h> 

Game::Game(void)
  : snake(25, 5) {

    create_walls();
      int counter = 0;
  while (1) {
    counter++;
    render();
    if (counter >= 5) {
      update();
      counter = 0;
    }
    usleep(100'000);  // 100ms

  }
}


void Game::create_walls(void) {
  // (0, 0) is top left
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (x == 0 || y == 0 || x == WIDTH-1 || y == HEIGHT-1) {
        walls.push_back(Wall(x, y));
      }
    }
  }
}

void Game::render(void) {
  canvas.clear();

  // WALLS
  for(auto wall : walls) {
    // canvas.draw_symbol(wall.x(), wall.y(), '#');
    wall.render(&canvas);
  }
  snake.render(&canvas);

  canvas.output_to_terminal();
}

void Game::process_keyboard_input(void) {
  Controller::Key pressedKey = Controller::get_key_press();

  switch (pressedKey) {
    case Controller::Key::DOWN: snake.down(); break;
    case Controller::Key::UP: snake.up(); break;
    case Controller::Key::LEFT: snake.left(); break;
    case Controller::Key::RIGHT: snake.right(); break;
  }
}

void Game::update(void){
    process_keyboard_input();

    // Dynamic state changes !!
    snake.update();
}