/*******************************************************************************************
 Andy Vicario
 cs162-400
 11/25/18
 
Implementation file for spaces. Holds functions for setting pointers for each child objects space pointers
 *******************************************************************************************/

#include "Spaces.hpp"

//getter functions for returning locations
Spaces *Spaces::getTop()
{
    return top;
}

Spaces *Spaces::getBottom()
{
    
    return bottom;
}

Spaces *Spaces::getLeft()
{
    return left;
}

Spaces *Spaces::getRight()
{
    return right;
}

//setter functions
void Spaces::setTop(Spaces *tmp)
{
    top = tmp;

}

void Spaces::setBottom(Spaces *tmp)
{
    bottom = tmp;
    
}

void Spaces::setLeft(Spaces *tmp)
{
    left = tmp;
    
}

void Spaces::setRight(Spaces *tmp)
{
    right = tmp;
    
}


