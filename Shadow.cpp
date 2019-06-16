//
//  Shadow.cpp
//  FInalProject
//
//  Created by ANDY VICARIO on 12/3/18.
//  Copyright © 2018 ANDY VICARIO. All rights reserved.
//

#include "Shadow.hpp"

#include "Shadow.hpp"

Shadow::Shadow()
{

    strength = 12;
    armor = 1;
    
}

//Process and sends attack roll to game. Polymorphic based on dice stats and special abilities
int Shadow::attack()
{
    int attackRoll;
    
    attackRoll = (rand() % 12 +1); //polymorphic attack roll function will vary based on character used
    
    return attackRoll;
    
}

//Process and sends defense roll to game. Polymorphic based on dice stats and special abilities
int Shadow::defend() //polymorphic defense roll function
{
    int defense;
    
    int charm;
    charm = rand() % 2;  //50% chance to use charm, if charm succeeds, huge defense output prevents damage
    
    if(charm == 0 ) //If charm is false, regular die roll
    {
        defense = (rand() % 6 +1);
        
    }
    else
    {
        defense = 100000;
    }
    
    
    return defense;
    
}

int Shadow::setStrength(int attackDamage)
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

