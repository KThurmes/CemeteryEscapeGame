/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Space is a parent class describing a space in the game 
board. It contains pointers to its four neighboring Spaces, an Item, a 
bool for whether there is a character on the space or not, whether the 
sSpace is passable by a Character or not, whether it is being hit with 
a NPC's glare or not, whether it has a key or not. It also has a flag 
for spawning a new Ghost. It contains strings to describe what kind of 
space it is and to store the print symbol of the space. There are also 
ints to describe where in the gameBoard grid the Space is.

The methods in this Class are primarily getters and setters. 
Essentially, the only non-trivial method is pickUpItem(), which is 
functionally a "getter" but it also sets the item member to null 
before returning the Item that used to be the Space's item.
*********************************************************************/

#include "Space.hpp"
#include "Item.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Space::Space()
{
    top = 0;
    right = 0;
    bottom = 0;
    left = 0;
    hasCharacter = false;
    item = 0;
    spawnGhostEvent = false;
    glare = false;
    hasKey = false;
}

void Space::setTop(Space *newTop)
{
    top = newTop;
}

void Space::setRight(Space *newRight)
{
    right = newRight;
}

void Space::setBottom(Space *newBottom)
{
    bottom = newBottom;
}

void Space::setLeft(Space *newLeft)
{
    left = newLeft;
}

void Space::setHasCharacter(bool doesIt)
{
    hasCharacter = doesIt;
}

Space *Space::getTop()
{
    return top;
}
Space *Space::getRight()
{
    return right;
}
Space *Space::getBottom()
{
    return bottom;
}
Space *Space::getLeft()
{
    return left;
}
bool Space::getPassable()
{
    return passable;
}

bool Space::getHasCharacter()
{
    return hasCharacter;
}

void Space::dropItem(Item *dropped)
{
    this->item = dropped;
}

bool Space::hasItem()
{
    return (this->item != 0);
}

/********************************************************************* 
** Description: pickUpItem returns a pointer to the Space's item 
member and sets their item pointer to null.
*********************************************************************/
Item *Space::pickUpItem()
{

    if (hasItem())
    {
        cout << "There's a " << item->getItemName() << " here. Would you like to pick it up?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int selection = getNumberBetween(1, 2);
        //return pointer to item and set Space's item pointer to null.
        if (selection == 1)
        {
            Item *toBeReturned = item;
            item = 0;
            return toBeReturned;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

string Space::getSpaceType()
{
    return spaceType;
}

bool Space::getSpawnGhost()
{
    return spawnGhostEvent;
}

void Space::setSpawnGhost(bool spawnGhost)
{
    spawnGhostEvent = spawnGhost;
}

void Space::setRowCol(int row, int col)
{
    this->row = row;
    this->col = col;
}

int Space::getRow()
{
    return row;
}
int Space::getCol()
{
    return col;
}

void Space::setGlare(bool gl)
{
    glare = gl;
}

bool Space::getGlare()
{
    return glare;
}

void Space::setHasKey(bool key)
{
    hasKey = key;
}

bool Space::getHasKey()
{
    return hasKey;
}