#include "Ghost.hpp"
#include "NPC.hpp"
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;

Ghost::Ghost
{
    location = 0;
    symbol = "G";
}

Ghost::~Ghost()
{
}

void Ghost::move()
{
    //Randomly choose to turn or step
    int moveOption = getRandomInt(0, 1);

    //turn
    if (moveOption == 0)
    {
        //choose to turn right or left
        moveOption = getRandomInt(0, 1);
        turn(moveOption);
    }
    //step forward
    else if (moveOption == 1)
    {
        step();
    }
    else
    {
        //something went wrong
    }
}

int Ghost::interact()
{
    cout << "Was that a cool breeze or the clammy embrace of the undead?" << endl;
    cout << "Either way, you are left feeling slightly worse now than before the chill came over you." << endl;
    cout << endl;
    cout << "-1 health" << endl
         << endl;
    return -1;
}
