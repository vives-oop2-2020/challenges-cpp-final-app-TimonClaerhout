#pragma once

class Snake {

  public:
    Snake(int x, int y);

  public:
    int x(void);
    int y(void);

  private:
    int _x = 0;
    int _y = 0;
};