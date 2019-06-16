/*******************************************************************************************
 Andy Vicario
 cs162-400
 11/25/18
 
 Header file for Spaces class. Contains pointers for created objects to link them together, 
 as well as virtual prompText and roomActions functions that work as a menu for each object made
*******************************************************************************************/
#ifndef Spaces_hpp
#define Spaces_hpp

#include <iostream>
#include <string>

class Spaces
{
protected:
    
    Spaces *top = nullptr;
    Spaces *bottom = nullptr;
    Spaces *left = nullptr;
    Spaces *right = nullptr;
    bool completed;
    
    
public:
    
    virtual void promptText() = 0;                  //Prompts user for choice and reacts based on that choice
    virtual int roomActions() = 0;
    
//Used to set each inherited spaces pointers to point to adjacent rooms
    Spaces *getTop();
    Spaces *getBottom();
    Spaces *getLeft();
    Spaces *getRight();
    void setTop(Spaces *tmp);
    void setBottom(Spaces *tmp);
    void setLeft(Spaces *tmp);
    void setRight(Spaces *tmp);
    
    virtual ~Spaces() {}
    
};



#endif /* Spaces_hpp */
