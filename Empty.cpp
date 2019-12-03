#include "Space.hpp"
#include "Empty.hpp"
#include "getNumberBetween.hpp"
#include <iostream>
using std::cout;
using std::endl;

Empty::Empty()
{
    printSymbol = " ";
    spaceType = "empty";
    spawnGhostEvent = 0;
    item = 0;
    passable = true;
    hasCharacter = false;
}

void Empty::printSpaceTop()
{
    cout << "   ";
}

void Empty::printSpaceMiddle()
{
    cout << " " << printSymbol << " ";
}

void Empty::printSpaceBottom()
{
    cout << "   ";
}

Empty::~Empty()
{
}

void Empty::interact(Inventory *playersInventory)
{
}
void Empty::changeToDefaultSymbol()
{
    printSymbol = " ";
}
