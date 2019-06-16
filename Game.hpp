//Andy Vicario
//cs162-400
//11/25/18

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <string>

#include "Spaces.hpp"
#include "Character.hpp"
#include "ChildSpaces.hpp"
#include "Hero.hpp"
#include "Shadow.hpp"

class Game
{
private:
    
    Spaces *ll;         //lower left
    Spaces *ul;         //upper left
    Spaces *lc;         //long corridor
    Spaces *ur;         //upper right
    Spaces *lr;         //Lower Right
    Spaces *cy ;         //Courtyard
    Character *fighter1;
    Character *fighter2;
    
public:
    
    void gameBuilder();
    void playGame();
    void printMap();
    void startPrompt();
    void finalFight( int heroStr);
};


#endif /* Game_hpp */
