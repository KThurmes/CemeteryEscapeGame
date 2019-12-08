#include "Gravestone.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "Inventory.hpp"
#include "enterToContinue.hpp"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

Gravestone::Gravestone()
{
    hasKey = false;
    passable = false;
    printSymbol = "t";
}
Gravestone::~Gravestone()
{
}
string Gravestone::printSpaceTop()
{
    return "   ";
}
string Gravestone::printSpaceMiddle()
{
    return (" " + printSymbol + " ");
}
string Gravestone::printSpaceBottom()
{
    return "   ";
}

void Gravestone::interact(Inventory *playersInventory)
{
    string tempThrowAway;
    cout << "This gravestone looks a little wobbly. Jostle it a bit?" << endl;
    cout << "1. Yeah!" << endl;
    cout << "2. No, thanks." << endl;
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        cout << "Dude. Not cool. Now you've angered the spirit of this poor dead person and created a new ghost." << endl;
        cout << "Serves you right." << endl
             << endl;
        ;

        //Set the flag to spawn a ghost.
        spawnGhostEvent = true;
        passable = true;

        if (hasKey)
        {
            cout << "But hey! It looks like there was a key under there!" << endl;
            cout << "You'll have to wait until the ghost leaves to get it, though." << endl;
        }
    }
    else if (selection == 2)
    {
        if (!cleaned)
        {
            cout << "Hmmm... This gravestone looks a little dirty. Clean it off?" << endl;
            cout << "1. Yeah, I'm sure this person's family will appreciate it." << endl;
            cout << "2. Naw, let's get back to the task at hand." << endl;
            cleaned = true;
            selection = getNumberBetween(1, 2);
            if (selection == 1)
            {
                cout << "Here's what the gravestone says: " << endl;
                //###TODO Make messages for gravestones
            }
            if (selection == 2)
            {
                cout << "Right. Better keep moving." << endl;
            }
        }
    }
    enterToContinue();
}

void Gravestone::setHasKey(bool key)
{
    this->hasKey = key;
}

void Gravestone::changeToDefaultSymbol()
{
    printSymbol = "t";
}

void Gravestone::setEngraving(string message)
{
    engraving = message;
}