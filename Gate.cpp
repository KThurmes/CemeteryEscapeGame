/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Gate is a child class of Space. It represents an 
impassible space that can become passible if the player has a key in 
their inventory when they interact with it.
*********************************************************************/

#include "Gate.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "enterToContinue.hpp"
#include <string>
using std::cout;
using std::endl;
using std::string;

Gate::Gate()
{
    passable = false;
    printSymbol = "=";
    spaceType = "gate";
}
Gate::~Gate()
{
}

string Gate::printSpaceTop()
{
    return "   ";
}
string Gate::printSpaceMiddle()
{
    return ("=" + printSymbol + "=");
}
string Gate::printSpaceBottom()
{
    return "   ";
}

/********************************************************************* 
** Description: interact conducts the interaction between the player 
and the space. Gate's interact function allows the player to see if 
it is locked, or to open it with a key. Once it is opened, the space 
becomes passable.
*********************************************************************/
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
    enterToContinue();
}
