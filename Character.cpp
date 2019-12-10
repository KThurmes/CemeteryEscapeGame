/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Character is a parent class of objects. All entities 
that move around on the game board are members of the Character class.
It has data members for its location and the symbol used to represent
it on the game board. It has member setter and getter functions. It 
also declares virtual functions for picking up a new item and 
deleting the character.
*********************************************************************/
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
    //If the character is already on the board, change their previous Space to hasCharacter==false.
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