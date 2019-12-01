#include "Gate.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

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

void Gate::interact()
{
    cout << "There's a gate here. Would you like to open it?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Beter not." << endl;
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        passable = true;
        gateOpened = true;
        //###TODO Change the visualization eventually.
    }
}