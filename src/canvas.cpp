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
}