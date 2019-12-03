#include "Gate.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Gate::Gate()
{
    passable = false;
    printSymbol = "=";
    spaceType = "gate";
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
    cout << "=" << printSymbol << "=";
}
void Gate::printSpaceBottom()
{
    cout << "   ";
}

void Gate::interact(Inventory *playersInventory)
{
    cout << "There's a gate here!" << endl;
    int keyIndex = playersInventory->findItem("key");
    bool hasKey = (keyIndex < playersInventory->getMaxItems());
    if (hasKey)
    {
        if (passable == false)
        {
            cout << "It looks like the key will fit. Unlock it?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            int selection = getNumberBetween(1, 2);
            if (selection == 1)
            {
                cout << "The gate is unlocked!" << endl;
                passable = true;
                //###TODO Change the visualization eventually.
            }
            else
            {
                cout << "Okay then." << endl;
            }
        }
    }
    else
    {
        cout << "It looks locked." << endl;
    }
}

void Gate::changeToDefaultSymbol()
{
    printSymbol = "=";
}