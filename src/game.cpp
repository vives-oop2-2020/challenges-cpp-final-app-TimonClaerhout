#include "game.h"
#include <unistd.h> 
#include <stdlib.h>
#include <time.h> 
#include "fstream"

Game::Game(void)
  : snake(25, 5) {
    canvas.modifyHighscore(scoreboard.giveHighscore());
    create_walls();
    create_fruits();
    snakes.push_back(Snake(snake.x()+1,snake.y()));
    snakes.push_back(Snake(snake.x()+2,snake.y()));
    srand(time(NULL));
    game_loop();
}

void Game::game_loop(void) {
  int counter = 0;
  while (!gameOver) {
    counter++;
    render();
    if (counter >= 3) {
      update();
      counter = 0;
    }
    change_speed();
  }
  scoreboard.save_score(canvas.giveScore());
  canvas.modifyHighscore(scoreboard.giveHighscore());
  canvas.output_to_terminal();
  go_to_menu();
}

void Game::go_to_menu(void){
  if(canvas.giveScore() > scoreboard.giveHighscore())
  {
    std::cout << "Congrats on beating the highscore, you're a god!!" << std::endl;
    usleep(1'000'000);
    std::cout << "Moving to menu ..." << std::endl;    
  } else {
    std::cout<<"Thanks for playing!" <<std::endl;
  }

  usleep(2'000'000);
  Menu menu;
}

void Game::change_speed(void){
    if(canvas.giveScore() >= 40 && canvas.giveScore() < 80)
    {
      delay = 80'000; //80ms
    }
    else if (canvas.giveScore() >= 80 && canvas.giveScore() < 120)
    {
      delay = 60'000; //60ms
    }
    else if (canvas.giveScore() >= 120)
    {
      delay = 40'000; //40ms
    }
    usleep(delay);
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
    // canvas.draw_symbol(wall.x(), wall.y(), 'X');
    fruit.render(&canvas);
  }

    for(auto snake : snakes) {
    // canvas.draw_symbol(wall.x(), wall.y(), 'O');
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
    check_for_collisions_with_tail(); 

    snake.update();

    check_for_collisions_with_fruits(); 

    if(snakes.size() >= 3){
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

    snakes.push_back(Snake(snake.x(),snake.y()));
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
