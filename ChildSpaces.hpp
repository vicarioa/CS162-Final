/*******************************************************************************************
 Andy Vicario
 cs162-400
 11/25/18
 
Header file for implementation of derived child space classes
 *******************************************************************************************/
#ifndef ChildSpaces_hpp
#define ChildSpaces_hpp

#include <iostream>

#include "Spaces.hpp"
#include "Validate.hpp"

class courtYard : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~courtYard() {}
    
};

class lowerLeft : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~lowerLeft() {}
};

class upperLeft : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~upperLeft() {}
};

class longCorridor : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~longCorridor() {}
};



class upperRight : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~upperRight() {}
};

class lowerRight : public Spaces
{
public:
    void promptText();
    int roomActions();
    
    ~lowerRight() {}
};


#endif /* ChildSpaces_hpp */
