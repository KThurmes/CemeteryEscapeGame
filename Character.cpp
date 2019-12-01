#include "Character.hpp"
#include "Space.hpp"

string Character::getSymbol()
{
    return this->symbol;
}

void Character::setLocation(Space *theSpace)
{
    location = theSpace;
}