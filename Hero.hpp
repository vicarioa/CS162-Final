/*******************************************************************************************
 Andy Vicario
 cs162-400
 11/25/18
 
Header file for hero class
*******************************************************************************************/

#ifndef Hero_hpp
#define Hero_hpp

#include <iostream>
#include "Character.hpp"


class Hero : public  Character
{
    
public:
    int attack();
    int defend();
    int getArmor() { return armor; }
    int getStrength() { if(strength < 0) strength = 0; return strength; }
    int setStrength(int attackDamage);
    
    
    Hero();
    ~Hero() {} //virtual destructor for base class pointers
    
    
    
protected:
    
    
    
};

#endif /* Hero_hpp */
