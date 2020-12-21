#include "scoreboard.h"
#include <fstream>

void Scoreboard::save_score(int score){
    // Create and open a text file
    std::ofstream MyFile("scoreboard.txt",std::ios::app);
  // Write to the file
  MyFile << score << "\n";
  MyFile.close();
}

int Scoreboard::giveHighscore(void){
    int number = 0;
    int highnumber = 0;
    // Read from the text file
    std::ifstream MyReadFile("scoreboard.txt");
    while (MyReadFile >> number) {
        if(number > highnumber){
            highnumber = number;
        }
    }
    return highnumber;
}