/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Empty is a child class of Space. It represents a 
generic Space with no particular features. Characters can move 
through it unimpeded.
*********************************************************************/
#include "Space.hpp"
#include "Empty.hpp"
#include "getNumberBetween.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Empty::Empty()
{
    printSymbol = " ";
    spaceType = "empty";
    spawnGhostEvent = 0;
    item = 0;
    passable = true;
    hasCharacter = false;
}

string Empty::printSpaceTop()
{
    return "   ";
}

string Empty::printSpaceMiddle()
{
    if (item != 0)
    {
        return " # ";
    }
    else
    {
        return " " + printSymbol + " ";
    }
}

string Empty::printSpaceBottom()
{
    return "   ";
}

Empty::~Empty()
{
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: interact conducts the interaction between the player 
and the space. Empty's interact function does nothing.
*********************************************************************/
void Empty::interact(Inventory *playersInventory)
{
}
