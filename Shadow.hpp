#ifndef Vampire_hpp
#define Vampire_hpp

#include <iostream>
#include <string>

#include "Character.hpp"

class Shadow : public Character
{
public:
    
    int attack();
    int defend();
    int getArmor() { return armor; }
    int getStrength() { if(strength <0) strength = 0; return strength; }
    int setStrength(int attackDamage);
    
    Shadow();
    ~Shadow() {} //virtual destructor for base class pointers
    
};

#endif /* Vampire_hpp */
