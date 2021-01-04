#include "wall.h"
#include "json.hpp"
#include <fstream>

using namespace nlohmann;

Wall::Wall(int x, int y)
: Entity(x,y) {
}

void Wall::render(Canvas * canvas) {
  // create a JSON value with different types
  // json j =
  //  {
  //      {"wall", "&"}
  //  
  //  };
  //  auto v6 =  j["wall"].get<std::string>();
  std::ifstream ifs("symbol.json");
  json jf = json::parse(ifs);
  //fs >> j;
  std::string v6 =  jf["wall"];
  char symbol = v6[0];
  canvas->draw_symbol(x(), y(), symbol);};
