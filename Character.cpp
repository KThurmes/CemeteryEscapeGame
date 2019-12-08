#include "Character.hpp"
#include "Space.hpp"
#include <iostream>

using std::cout;
using std::endl;

string Character::getSymbol()
{
    return this->symbol;
}

void Character::setLocation(Space *theSpace)
{
    if (location != 0)
    {
        location->setHasCharacter(false);
    }
    location = theSpace;
    location->setHasCharacter(true);
}

Space *Character::getLocation()
{
    return location;
}