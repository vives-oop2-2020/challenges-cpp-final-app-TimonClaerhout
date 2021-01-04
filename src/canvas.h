#pragma once

class Canvas {

  public:
    Canvas(void);

  public:
    void clear(void);
    void draw_symbol(int x, int y, char symbol);

  public:
    void output_to_terminal(void);

  public:
    void modifyScore(int scored);
    int giveScore(void);
    void modifyHighscore(int highscore1);
    void intro(void);

  private:
    static const unsigned int WIDTH = 30;
    static const unsigned int HEIGHT = 10;
    int score = 0;
    int highscore;
    char screen[WIDTH][HEIGHT];
};