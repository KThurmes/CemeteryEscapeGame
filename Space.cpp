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
    discovered = false;
}

void Space::setIDNum(int id)
{
    idNum = id;
}

int Space::getIDNum()
{
    return idNum;
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
void Space::setPrintSymbol(string symb)
{
    printSymbol = symb;
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

Item *Space::pickUpItem()
{

    if (hasItem())
    {
        cout << "There's a " << item->getItemName() << " here. Would you like to pick it up?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int selection = getNumberBetween(1, 2);
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

void Space::discover()
{
    discovered = true;
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