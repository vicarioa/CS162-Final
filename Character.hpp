//Andy Vicario
//cs162-400
//11/25/18

#ifndef Character_hpp
#define Character_hpp

#include <iostream>
#include <string>

class Character
{
protected:
    int strength = 0;;
    int armor = 0;
    
public:
    
    virtual int attack() = 0;
    virtual  int defend() = 0;
    virtual int getArmor() = 0;
    virtual int getStrength() = 0;
    virtual int setStrength(int attackDamage) = 0;
    
    virtual ~Character() {} //virtual destructor for proper memory deletion
};



#endif /* Character_hpp */
