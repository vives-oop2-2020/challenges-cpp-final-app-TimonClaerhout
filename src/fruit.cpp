#include "fruit.h"
#include "json.hpp"
#include <fstream>

using namespace nlohmann;

Fruit::Fruit(int x, int y)
  : Entity(x, y) {
}

void Fruit::render(Canvas * canvas) {
  std::ifstream ifs("symbol.json");
  json jf = json::parse(ifs);
  auto symbolfile =  jf["fruit"].get<std::string>();
  char symbol = symbolfile[0];
  canvas->draw_symbol(x(), y(), symbol);
}