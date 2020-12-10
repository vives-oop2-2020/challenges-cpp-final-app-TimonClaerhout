#include "scoreboard.h"
#include <fstream>
#include <iostream>
#include <string>

void Scoreboard::save_score(int score){
    // Create and open a text file
    std::ofstream MyFile("scoreboard.txt");
  // Write to the file
  MyFile << score;
}

int Scoreboard::giveHighscore(void){
    std::string line;
    int highnumber = 0;
    // Read from the text file
    std::ifstream MyReadFile("scoreboard.txt");
    while (getline (MyReadFile, line)) {
        if(std::stoi(line) > highnumber){
            highnumber = std::stoi(line);
        }
    }
    return highnumber;
}