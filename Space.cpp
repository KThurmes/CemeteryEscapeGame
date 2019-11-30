#include "Space.hpp"
#include <iostream>
using std::cout;

Space::Space()
{
    top = 0;
    right = 0;
    bottom = 0;
    left = 0;
    character = 0;
}

void Space::setCharacter(Character *theChar)
{
    this->character = theChar;
}