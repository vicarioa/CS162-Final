//Andy Vicario
//cs162-400
//11/25/18
//Main file for game. Calls game builder function and gameplay function


#include <iostream>
#include <ctime>
#include <cstdlib>


#include "Game.hpp"

int main() {
    
    srand(time(NULL));
    
    Game game;
    
    game.printMap();
    game.startPrompt();
    game.gameBuilder();
    game.playGame();

}
