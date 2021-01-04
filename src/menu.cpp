#include "menu.h"
#include <iostream>
#include "game.h"
#include <stdlib.h>

Menu::Menu(void){
    showmenu();
}

void Menu::showmenu(void){

    do {
        system("clear");
        std::cout<< "Welcome to the Snake game!!" << std::endl;
        std::cout<< "Press a number to navigate through the menu:" << std::endl;
        std::cout<< "1. Play Game" << std::endl << "2. Instructions" << std::endl << "3. Quit\n";
        std::cin >> choice;
        switch(choice){
            case 3:
                break;
            case 2:
                instruction();
                break;
            case 1:
                Game game;
                break;
        }
    } while (choice != 3);
}

void Menu::instruction(void){
    do{
        system("clear");
        std::cout<<"By the beginning of the snake game, the head of the snake will move." << std::endl;
        std::cout<<"Use the arrow keys of your keyboard to move the head of the snake." << std::endl;
        std::cout<<"Each time you eat a fruit on the field then your snake will be bigger and your score higher."<< std::endl;
        std::cout<<"But watch out!! If you hit the wall or your own tail of the snake then is the game over."<< std::endl;
        std::cout<<"The higher your score is, the faster the snake will move, can you beat the highscore?"<< std::endl;
        std::cout<<"Good luck!!\n\n"<< std::endl;
        std::cout<<"1. Go Back\n"; std::cin>> choice;
    } while(choice != 1);
}
