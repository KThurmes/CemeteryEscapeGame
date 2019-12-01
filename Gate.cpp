#include "Gate.hpp"
#include "Space.hpp"
#include <iostream>
using std::cout;

Gate::Gate()
{
    gateOpened = false;
    passable = false;
}
Gate::~Gate()
{
}

void Gate::printSpaceTop()
{
    cout << "   ";
}
void Gate::printSpaceMiddle()
{
    cout << "===";
}
void Gate::printSpaceBottom()
{
    cout << "   ";
}