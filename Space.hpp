#ifndef SPACE_HPP
#define SPACE_HPP
#include "Character.hpp"

class Space
{
protected:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    Character *character;

public:
    Space();
    virtual void printSpaceTop() = 0;
    virtual void printSpaceMiddle() = 0;
    virtual void printSpaceBottom() = 0;
    void setCharacter(Character *);
};

#endif