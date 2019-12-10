/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Fence is a child class of Space. It is initially 
impassible, but can be rendered passible with the use of a sheet.
*********************************************************************/

#include "Fence.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "Inventory.hpp"
#include "enterToContinue.hpp"
#include <string>
using std::cout;
using std::endl;
using std::string;

Fence::Fence()
{
    passable = false;
    printSymbol = "-";
    spaceType = "fence";
}

Fence::~Fence()
{
}

string Fence::printSpaceTop()
{
    return "   ";
}
string Fence::printSpaceMiddle()
{
    return ("-" + printSymbol + "-");
}
string Fence::printSpaceBottom()
{
    return "   ";
}

void Fence::interact(Inventory *playersInventory)
{
    cout << "There's a fence here!" << endl
         << endl;
    cout << "This is a pretty solid-looking fence, and it's got spikes on the top," << endl;
    cout << "so I don't think I can climb over..." << endl;

    //Determine if player has sheet
    int sheetIndex = playersInventory->findItem("sheet");
    bool hasSheet = (sheetIndex < playersInventory->getMaxItems());

    if (hasSheet)
    {
        //Make sure fence isn't passable yet
        if (passable == false)
        {
            cout << "But maybe... What if I try throwing this sheet over the top to cover" << endl;
            cout << "the spikes? Then I might be able to climb over it!" << endl
                 << endl;
            cout << "Throw the sheet?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            int selection = getNumberBetween(1, 2);
            if (selection == 1)
            {
                cout << "If I'm really careful, I think I can climb over!" << endl;
                //make fence passable
                passable = true;
                //remove item from player inventory
                playersInventory->useItem(sheetIndex);
            }
            else
            {
                cout << "Yeah, that plan sounds too risky." << endl;
            }
        }
    }
    enterToContinue();
}