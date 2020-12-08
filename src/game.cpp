#include "game.h"

Game::Game(void)
  : snake(25, 5) {

  create_walls();
  render();
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

void Game::update(void){
    process_keyboard_input();
    check_for_collisions_with_walls();

    // Dynamic state changes !!
    snake.update();
}