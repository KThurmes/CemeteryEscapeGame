#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
using std::cout;
using std::endl;

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

void Empty::interact()
{
}