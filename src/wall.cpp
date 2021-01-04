#include "wall.h"
#include "json.hpp"
#include <fstream>

using namespace nlohmann;

Wall::Wall(int x, int y)
: Entity(x,y) {
}

void Wall::render(Canvas * canvas) {
  std::ifstream ifs("symbol.json");
  json jf = json::parse(ifs);
  auto symbolfile =  jf["wall"].get<std::string>();
  char symbol = symbolfile[0];
  canvas->draw_symbol(x(), y(), symbol);
}
