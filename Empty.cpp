#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
using std::cout;
using std::endl;

/* void Empty::printSpace()
{
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "|   |" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
} */

void Empty::printSpaceTop()
{
    cout << "   ";
}

void Empty::printSpaceMiddle()
{
    if (this->character == 0)
    {
        cout << "   ";
    }

    else
    {
        cout << " " << this->character->getSymbol() << " ";
    }
}

void Empty::printSpaceBottom()
{
    cout << "   ";
}