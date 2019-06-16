//Andy Vicario
//cs162-400
//11/25/18

#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

/**************************************************************************************
Creates all rooms and connects them to each other via spaces pointers. 
 Could also do this using constructors of each class
**************************************************************************************/
void Game::gameBuilder()
{
    //Build all instances of space objects
    cy = new courtYard;
    ll = new lowerLeft;
    ul = new upperLeft;
    lc = new longCorridor;
    ur = new upperRight;
    lr = new lowerRight;
    
    //set couryard pointers
    cy -> setTop(nullptr);
    cy -> setBottom(nullptr);
    cy -> setLeft(ll);
    cy -> setRight(lr);

    //Set lower left room pointers
    ll -> setTop(ul);
    ll -> setBottom(nullptr);
    ll -> setLeft(nullptr);
    ll -> setRight(cy);
    
    //set upper left room pointers
    ul -> setTop(lc);
    ul -> setBottom(ll);
    ul -> setLeft(nullptr);
    ul -> setRight(nullptr);
    
    //set long corridor pointers
    lc -> setTop(nullptr);
    lc -> setBottom(nullptr);
    lc -> setLeft(ul);
    lc -> setRight(ur);
    
    //set upper right room pointers
    ur -> setTop(lc);
    ur -> setBottom(lr);
    ur -> setLeft(nullptr);
    ur -> setRight(nullptr);
    
    //lower right room pointers
    lr -> setTop(ur);
    lr -> setBottom(nullptr);
    lr -> setLeft(cy);
    lr -> setRight(nullptr);

}

//Game loop moves player and performs actions based on choices made
void Game::playGame()
{
    //Created hero and final boss for a later battle, if you make it there!
    fighter1 = new Hero;
    fighter2 = new Shadow;
    
    Spaces *currentSpace = cy;                  //Initialize to courtyard to start game
    int strength = 60;                          //Initialize strenght to 60, dec each round, pass to hero for final battle
    int actionChoice;
    bool items[3] = { false, false, false};     //Item container. Set all found to false, then true if found
    int itemCount = 0;                          //Keep track of number of items to display gem count
    bool run = true;                            //Initial state to run game
    
    //While player is not dead and player has not escaped
    while(strength > 0 && run== true)
    {
        cout << "Strength left: " << strength << endl;
        cout << "Gem Count: " << itemCount << endl << endl;
        
        currentSpace -> promptText();                   //Present unique choices for each room
        actionChoice = currentSpace -> roomActions();   //Validates and returns actions for room based on promptText
        
        if(actionChoice == 1)
        {
            currentSpace = currentSpace -> getTop();
            printMap();

        }
        else if(actionChoice == 2)
        {
            currentSpace = currentSpace -> getBottom();
            printMap();

        }
        else if(actionChoice == 3)
        {
            currentSpace = currentSpace -> getLeft();
            printMap();

        }
        else if(actionChoice == 4)
        {
            currentSpace = currentSpace -> getRight();
            printMap();

        }
        else if(actionChoice == 5)
        {
            //do nothing/ waste time in game, restart loop
            printMap();
        }
        else if(actionChoice == 6)
        {
            items[itemCount] = true;
            itemCount++;
            cout << " You now have " << itemCount << " gems" << endl;
            printMap();
        }
        //Check number of gems currently in array container. If they haven't all been found, loop game again.
        else if(actionChoice == 7)
        {
            if(items[0] == true && items[1] == true && items[2] == true)
            {
                cout << "You have found all of the gems and escape.. Or so you think!!" << endl << endl;
                strength = 60 - strength; //Set strength to difference and pass into final Fight
                run = false;
                finalFight(strength);
                
            }
            else
            {
                cout << "You don't have enough gems to fill all the slots, so nothing happens" << endl << endl;
                printMap();
            }
            
        }
        //Quit game, no map printed
        else
        {
            cout << "Thanks for playing!" << endl << endl;
            run = false;
        }

        strength--;
    }
    
//Memory clean up
    delete cy;
    delete ll;
    delete ul;
    delete lc;
    delete ur;
    delete lr;
    delete fighter1;
    delete fighter2;
    cy = nullptr;
    ll = nullptr;
    ul = nullptr;
    lc = nullptr;
    ur = nullptr;
    lr = nullptr;
    fighter1 = nullptr;
    fighter2 = nullptr;

}

//Display a map each turn for easier navigation
void Game::printMap()
{
    cout << "------------------------------------------------------------" << endl;
    cout <<"|                                                           |" << endl;
    cout <<"|                              3                            |" << endl;
    cout <<"|---D---------------------------------------------------D---|" << endl;
    cout <<"|       |                                           |       |" << endl;
    cout <<"|   2   |                                           |   4   |" << endl;
    cout <<"|       |                                           |       |" << endl;
    cout <<"|---D---|                                           |---D---|" << endl;
    cout <<"|       |                    6                      |       |" << endl;
    cout <<"|   1   D                                           D    5  |" << endl;
    cout <<"|       |                                           |       |" << endl;
    cout <<"|       |                                           |       |" << endl;
    cout << "------------<>--------------<>--------------<>--------------" << endl;
    cout << endl;

}

//Initial prompt of story and instructions
void Game::startPrompt()
{
    cout << "(Goal of the game is to find three diamonds to open south wall and escape)" << endl;
    cout << "You wake up in a dark courtyard." << endl;
    cout << "You have no idea how you got here." << endl << endl;
    cout << "A thick smog permeates the air. " << endl;
    cout << "You can feel it coat your nostrils with each breath you take." << endl;
    cout << "You can feel your life force fading, you need to get out of here!" << endl << endl;
    cout << "You see four walls, south, north, east and west " << endl;
    cout << "There are doors (D) located on the east and west walls." << endl << endl;
    cout << "The south seems different somehow, all you see are three diamond shaped slots." << endl;
    cout << "Could this weird wall have something to do to get out of here? " << endl << endl;;
    cout << "Better get going to try and find more clues!" << endl;
    cout << endl;
}
//Final fight, hero strength is set to what was left before opening the door.
void Game::finalFight(int heroStr)
{
    int p1dmg;
    int p2dmg;
    int p1def;
    int p2def;
    int damage;
    
    
    fighter1 -> setStrength(heroStr);       //use strength diff to subtract from current max HP
    
    cout << "You make it to a long corridor, you can see light at the end of the tunnel!!" << endl;
    cout << "But suddenly a shadow appears, you have met your original captor!" << endl << endl;
    cout << "You grab the nearest weapon you can find, and fight valiantly until..." << endl << endl;
    while(fighter1 -> getStrength() != 0 && fighter2 -> getStrength() != 0)
    {
        
        //Player 1 attacks and player 2 defense sequence
        p1dmg = fighter1 -> attack();
        p2def = fighter2 -> defend();
        
        damage = p1dmg - p2def - fighter2 -> getArmor();
        
        damage = fighter2 -> setStrength(damage);
        
        p2dmg = fighter2 -> attack();
        p1def = fighter1 -> defend();
        
        damage = p2dmg - p1def - fighter1 -> getArmor();
        
        damage = fighter1 -> setStrength(damage);
        
    }
    
    if(fighter1 -> getStrength() <= 0)
    {
        cout << "The shadow consumes you. All is lost... " << endl << endl;
        cout << " GAME OVER" << endl << endl;
    }
    else if( fighter2 -> getStrength() <= 0)
    {
        cout << " You defeat the shadow and escape! Freedom at last!!!" << endl;

    }
    else{ cout << "Weird stuff is happening" << endl;}
}
