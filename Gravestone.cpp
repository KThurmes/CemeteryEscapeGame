/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Gravestone is a child class of Space. It is initially 
impassible, but can be rendered passible if the player wiggles it a 
bit. However, when it is wiggled, it sets the spawnGhost flag to true 
and that can be used to trigger the spawning of a new Ghost
*********************************************************************/

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
    printSymbol = "n";
    cleaned = false;
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
    if (!passable == true)
    {
        return " " + printSymbol + " ";
    }
    else if (hasItem())
    {
        return " # ";
    }
    else
    {
        return "   ";
    }
}

string Gravestone::printSpaceBottom()
{
    return "   ";
}

/********************************************************************* 
** Description: interact conducts the interaction between the player 
and the space. Gravestone's interact function allows the player to 
wiggle the stone, clean it off, and find the key underneath it (if 
it's there)
*********************************************************************/
void Gravestone::interact(Inventory *playersInventory)
{
    int selection;
    if (!hasKey)
    {
        cout << "This gravestone looks a little wobbly. Jostle it a bit?" << endl;
        cout << "1. Yeah!" << endl;
        cout << "2. No, thanks." << endl;
        selection = getNumberBetween(1, 2);
        if (selection == 1)
        {
            cout << endl
                 << "Dude. Not cool. Now you've angered the spirit of this poor dead person \nand created a new ghost." << endl;
            cout << "Serves you right." << endl
                 << endl;

            //Set the flag to spawn a ghost.
            spawnGhostEvent = true;
            passable = true;
            cleaned = true;
        }
    }

    //Allow user to choose to clean off the headstone
    if (!cleaned && !passable)
    {
        cout << endl
             << "Hmmm... This gravestone looks a little dirty. Clean it off?" << endl;
        cout << "1. Yeah, I'm sure this person's family will appreciate it." << endl;
        cout << "2. Naw, let's get back to the task at hand." << endl;
        cleaned = true;
        selection = getNumberBetween(1, 2);
        if (selection == 1)
        {
            cleaned = true;
        }
        if (selection == 2)
        {
            cout << "Right. Better keep moving." << endl;
            cleaned = false;
        }
    }
    //Print epitaph
    if (cleaned && !passable)
    {
        cout << "Here's what the gravestone says: " << endl;
        cout << this->engraving;
        cout << endl
             << endl;

        //Let player know there's a key there
        if (hasKey)
        {
            cout << "Hm. That's odd. There's a little secret compartment near the bottom of\this novelty gravestone. Open it?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            selection = getNumberBetween(1, 2);
            if (selection == 1)
            {
                cout << "Oh look! There's a spare gate key under here!" << endl
                     << endl;
                passable = true;
            }
            else
            {
                cout << "Okaaaaay. But there's probably something useful hidden in there." << endl
                     << endl;
            }
        }
    }

    enterToContinue();
}

void Gravestone::setEngraving(string message)
{
    engraving = message;
}