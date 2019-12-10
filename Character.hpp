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
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Space.hpp"

class Character
{
protected:
    Space *location;
    string symbol;

public:
    virtual void pickUpItem(Item *) = 0;
    string getSymbol();
    virtual ~Character(){};
    void setLocation(Space *);
    Space *getLocation();
};

#endif