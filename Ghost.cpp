/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Ghost is a child class of Character and NPC. They 
have a deathly glare and they make the people who run into them very 
hungry and cold.
********************************************************************/

#include "Ghost.hpp"
#include "NPC.hpp"
#include "Character.hpp"
#include <iostream>
#include "getRandomInt.hpp"
#include "enterToContinue.hpp"
#include <cstdlib>
using std::cout;
using std::endl;

Ghost::Ghost()
{
    location = 0;
    symbol = "G";
    glareRay = true;
}

Ghost::~Ghost()
{
}

/********************************************************************* 
** Description: Ghosts randomly choose whether to turn or move 
forward. They return their destination Space without moving to it 
just yet.
********************************************************************/
Space *Ghost::move()
{
    //Randomly choose to turn or step
    int moveOption = getRandomInt(0, 1);

    //turn
    if (moveOption == 0)
    {
        //choose to turn right or left
        moveOption = getRandomInt(0, 1);
        turn(moveOption);
        return location;
    }
    //step forward
    else
    {
        return step();
    }
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Ghosts can make their presence felt by humans who 
have the misfortune of running into them. interact returns -1 damage
for the player.
********************************************************************/
int Ghost::interact()
{
    cout << endl
         << "Was that a cool breeze or the clammy embrace of the undead?" << endl
         << endl;
    cout << "Either way, you are left feeling slightly worse now than before the \nchill came over you." << endl;
    cout << endl;

    enterToContinue();
    return -1;
}
