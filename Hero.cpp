/*******************************************************************************************
 Andy Vicario
 cs162-400
 11/25/18
 
 Implementation file for hero class. Used in final fight with Shadow boss after gem door is opened
 *******************************************************************************************/


#include "Hero.hpp"
#include <cstdlib>

Hero::Hero()
{
    strength = 60;          //Hero's health will effectively be used as a timer. Will decrement with each movement made
    armor = 0;
}

//Process and sends attack roll to game. Polymorphic based on dice stats and special abilities
int Hero::attack()
{
    int attackRoll;
    
    attackRoll = ((rand() % 6 +1) + (rand() % 6 + 1)); //polymorphic attack roll function will vary based on character used
    
    return attackRoll;
    
}

//Process and sends defense roll to game. Polymorphic based on dice stats and special abilities
int Hero::defend() //polymorphic defense roll function
{
    int defense;
    
    defense = ((rand() % 6 +1) + (rand() % 6 + 1));
    
    return defense;
    
}

int Hero::setStrength(int attackDamage)
{
    
    if( attackDamage < 0) //if attack yielded a number less than 0, no damage done
    {
        attackDamage = 0;
        
    }
    else
    {
        strength = strength - attackDamage;
    }
    
    return attackDamage;
    
}
