/*******************************************************************************************
Andy Vicario
cs162-400
11/25/18

Implementation file for all menu choices and available actions for each unique room.
Gets choice from user: Each room has four things to do, all waste time. Need
valid input for each number to make validation work. Also 1 = top, 2 = bottom,
3 = left, 4 = right, or 5 returns to do nothing,  for the sake of
onsistency on value return to playgame and to make sure nulllptrs are not accessed
*******************************************************************************************/

#include "ChildSpaces.hpp"

using std::cin;
using std::cout;
using std::endl;

//Courtyards prompts
void courtYard::promptText()
{
    cout << endl;
    cout << " You are currently in the courtyard (6)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] Wander aimlessly around the courtyard (Wastes Time) " << endl;
    cout << "[2] Try to escape using south wall (3 Diamond shaped gems are needed)" << endl;
    cout << "[3] Open door to lower left room (1) " << endl;
    cout << "[4] Open door to Room 5 " << endl;
    cout << "[5] Quit Game" << endl;
}

//Implementation of courtYard child class actions
int courtYard::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    if(choice == 1)
    {
        cout << "You waste precious, precious time and energy doing nothing of importance" << endl << endl;
        return 5;
    }
    else if( choice == 2 )
    {
        return 7;
    }
    else if(choice == 3)
    {
        return 3;
    }
    else if(choice ==4)
    {
        return 4;
    }
    else
    {
        return 8;
    }
    
}


//Lower left prompts for actions
void lowerLeft::promptText()
{
    cout <<endl;
    cout << " You are currently in the lower left room (1)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] go to upper left room (2) " << endl;
    cout << "[2] Check south wall of this room " << endl;
    cout << "[3] Check desk against the west wall of this room (Theres a gem here)" << endl;
    cout << "[4] Return to courtyard" << endl;
    cout << "[5] Quit Game" << endl;

}

int lowerLeft::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    cout << endl;
    
    if(choice == 1)
    {
        return 1;
    }
    else if( choice == 2 )
    {
        cout << "Nothing to see here " << endl << endl;
        return 5;
    }
    else if(choice == 3)
    {
        if(completed == false)
        {
            cout << "Theres a desk here, you found a gem inside the drawer!" << endl << endl;
            completed = true;
            return 6;
        }
        else
        {
            cout << "There is nothing left in the desk except dust and a few paper scraps" << endl << endl;
            return 5;
        }
    }
    else if(choice == 4)
    {
        return 4;
    }
    else
    {
        return 8;
    }
}

//Upper left rooms prompts for actions
void upperLeft::promptText()
{
    cout <<endl;
    cout << " You are currently in the  upper left room (2)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] go to the long corridor (3) " << endl;
    cout << "[2] Go back to lower left room (2) " << endl;
    cout << "[3] Check west wall of this room" << endl;
    cout << "[4] Check the east wall of this room" << endl;
    cout << "[5] Quit Game" << endl;

}

//Validates and takes actions for room based on associated promptText function
int upperLeft::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    cout << endl;
    
    if(choice == 1)
    {
        return 1;
    }
    else if( choice == 2 )
    {
        return 2;
    }
    else if(choice == 3)
    {
        cout << "There is a creepy painting of some dark, shadowy figure" << endl << endl;
        return 5;
    }
    else if(choice == 4)
    {
        cout << " Just a brick wall there..." << endl << endl;
        return 5;
    }
    else
    {
        return 8;
    }
}

//Long Corridor rooms prompts for actions
void longCorridor::promptText()
{
    cout <<endl;
    cout << " You are currently in the long corridor (3)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] Investigate north wall (Theres a gem here)" << endl;
    cout << "[2] Investigate south wall (Nothing here) " << endl;
    cout << "[3] Go to upper left room (2)" << endl;
    cout << "[4] Go to upper right room (4)" << endl;
    cout << "[5] Quit Game" << endl;

}

int longCorridor::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    cout << endl;
    
    if(choice == 1)
    {
        if(completed == false)
        {
            //Add a number to main gameplay loop to increment number of items in container
            cout << " There is a glint of something in an old suit of armor... You found a gem!" << endl << endl;
            completed = true;
            return 6;
        }
        else
        {
            cout << "There is nothing else here..." << endl << endl;
            return 5;
        }
    }
    else if( choice == 2 )
    {
        cout << "Just a long brick wall with various paintings of people you don't recognize" << endl << endl;
        return 5;
    }
    else if(choice == 3)
    {
        
        return 3;
    }
    else if(choice == 4)
    {
        return 4;
    }
    else
    {
        return 8;
    }
}

//Upper right rooms prompts for actions
void upperRight::promptText()
{
    cout <<endl;
    cout << " You are currently in the upper right room (4)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] Go to the long corridor (3)" << endl;
    cout << "[2] Go to the lower right room (5)" << endl;
    cout << "[3] Investigate west wall in room (Nothing here)" << endl;
    cout << "[4] Investigate east wall in room (Nothing here)" << endl;
    cout << "[5] Quit Game" << endl;

}

int upperRight::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    cout << endl;
    
    if(choice == 1)
    {
        return 1;
    }
    else if( choice == 2 )
    {
        return 2;
    }
    else if(choice == 3)
    {
        cout << "Just a brick wall there..." << endl << endl;
        return 5;
    }
    else if(choice == 4)
    {
        cout << " Just a brick wall there..." << endl << endl;
        return 5;
    }
    else
    {
        return 8;
    }
}

//Lower right rooms prompts for actions
void lowerRight::promptText()
{
    cout <<endl;
    cout << " You are currently in the lower right room (5)" << endl;
    cout << "What would you like to do?" << endl << endl;
    
    cout << "[1] Go to the upper right room (4)" << endl;
    cout << "[2] Examine a strange chest against the south wall (gem here) (5)" << endl;
    cout << "[3] Go to the courtyard (6)" << endl;
    cout << "[4] Investigate east wall in room (Nothing here)" << endl;
    cout << "[5] Quit Game" << endl;

}

int lowerRight::roomActions()
{
    int choice;
    choice = validate(1,5);
    
    cout << endl;
    
    if(choice == 1)
    {
        return 1;
    }
    else if( choice == 2 )
    {
        if(completed == false)
        {
            cout << "You open the chest and find a gem! One step closer to freedom!" << endl << endl;
            completed = true;
            return 6;
        }
        else
        {
            cout << "The chest is empty" << endl << endl;
            return 5;
        }

    }
    else if(choice == 3)
    {
        return 3;
    }
    else if(choice == 4)
    {
        cout << "Just another brick wall in a world full of them" << endl << endl;
        return 5;
    }
    else
    {
        return 8;
    }
}




