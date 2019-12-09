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

void Empty::interact(Inventory *playersInventory)
{
}
