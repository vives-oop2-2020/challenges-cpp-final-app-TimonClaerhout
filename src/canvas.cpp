#include "canvas.h"
#include <iostream>

Canvas::Canvas(void) {
  clear();
}

void Canvas::clear(void) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      screen[x][y] = ' ';
    }
  }
}

void Canvas::draw_symbol(int x, int y, char symbol) {
  screen[x][y] = symbol;
}

void Canvas::modifyScore(int scored){
  score += scored;
}

int Canvas::giveScore(void){
  return score;
}

void Canvas::modifyHighscore(int highscore1){
  highscore = highscore1;
}

void Canvas::intro(void){
  std::cout << "Welcome to the snake game!!" << std::endl;
  std::cout << "You can decide how big the field has to be, type the measurements and press enter to confirm" << std::endl;
  std::cout << "Good Luck!" << std::endl;
}

void Canvas::output_to_terminal(void) {
  system("clear");
  std::cout << "Score = " << score << std::endl;
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      std::cout << screen[x][y];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Highscore = " << highscore << std::endl;
}