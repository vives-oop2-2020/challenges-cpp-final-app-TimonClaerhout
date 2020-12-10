#include "game.h"
#include <unistd.h> 
#include <stdlib.h>
#include <time.h> 

Game::Game(void)
  : snake(25, 5) {

    create_walls();
    create_fruits();
    //srand(time(NULL));
      int counter = 0;
  while (!gameOver) {
    counter++;
    render();
    if (counter >= 3) {
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

void Game::create_fruits(void) {
  fruits.push_back(Fruit(3, 5));
}

void Game::render(void) {
  canvas.clear();

  // WALLS
  for(auto wall : walls) {
    // canvas.draw_symbol(wall.x(), wall.y(), '#');
    wall.render(&canvas);
  }

  snake.render(&canvas);

  // WALLS
  for(auto fruit : fruits) {
    // canvas.draw_symbol(wall.x(), wall.y(), '#');
    fruit.render(&canvas);
  }

    for(auto snake : snakes) {
    // canvas.draw_symbol(wall.x(), wall.y(), '#');
    snake.render(&canvas);
  }

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
    check_for_collisions_with_walls();
    
    // Dynamic state changes !!
    check_for_collisions_with_tail(); 
    snake.update();
    check_for_collisions_with_fruits(); 
    if(snakes.size() >= 1){
      snakes.erase(snakes.begin());
    }
      snakes.push_back(Snake(snake.x(),snake.y()));
}

void Game::check_for_collisions_with_walls(void) {
  int x = 0;
  int y = 0;
  snake.next_position(&x, &y);

  for(auto wall : walls) {
    if (x == wall.x() && y == wall.y()) {
      gameOver = true;
    }
  }
}

void Game::check_for_collisions_with_fruits(void) {
  int fruitToEat = -1;
  for (int i = 0; i < fruits.size(); i++) {
    if (snake.x() == fruits[i].x() &&
      snake.y() == fruits[i].y()) {
        fruitToEat = i;
      }
  }

  if (fruitToEat >= 0) {
    fruits.erase(fruits.begin() + fruitToEat);
    fruits.push_back(Fruit(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2)));
    canvas.modifyScore(10);
    //firstTail++;
    snakes.push_back(Snake(snake.x(),snake.y()));
    //if(firstTail == 1)
    //{
      //snakes.push_back(Snake(snake.x(),snake.y()));
    //}
  }
}

void Game::check_for_collisions_with_tail(void) {
  int x = 0;
  int y = 0;
  snake.next_position(&x, &y);
  for (int i = 0; i < snakes.size(); i++) {
    if (x == snakes[i].x() &&
      y == snakes[i].y()) {
        gameOver = true;
      }
  }
}