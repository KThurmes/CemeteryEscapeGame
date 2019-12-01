#include "Space.hpp"
#include <iostream>
using std::cout;

Space::Space()
{
    top = 0;
    right = 0;
    bottom = 0;
    left = 0;
    hasCharacter = false;
    passable = true;
    printSymbol = " ";
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
