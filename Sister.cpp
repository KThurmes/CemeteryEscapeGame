/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Sister is a child class of Character and NPC. The 
sister inherits from Character, but also has an additional data member
and function.
The additional data member is the found boolean which is a flag for 
sister having been found. The additional member function is simply a 
getter for found.
*********************************************************************/
#include "Sister.hpp"
#include "getRandomInt.hpp"
#include "Character.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "enterToContinue.hpp"
#include <cstdlib>
using std::cout;
using std::endl;

Sister::Sister()
{
    found = 0;
    location = 0;
    symbol = "g";
}

Sister::~Sister()
{
}

/********************************************************************* 
** Description: Sister randomly chooses whether to turn or move 
forward. The function returns their destination Space without moving 
to it just yet.
********************************************************************/
Space *Sister::move()
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
** Description: When the player encounters Sister, they have the 
option to take off her sheet and have her go home. The sheet falls 
to the ground and the player can pick it up. Sister disappears. The 
int that is returned is 0 because she does not do any damage to the 
player.
********************************************************************/
int Sister::interact()
{
    cout << endl;
    cout << "Hm. This ghost looks odd. Upon further inspection, it looks like it" << endl;
    cout << "might just be a person walking around in a white bedsheet." << endl;
    cout << endl;
    cout << "Pull the sheet?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        cout << endl
             << "Sister: \"Excuse you! I was practicing for Hamlet. It's called" << endl;
        cout << "\"method acting\" and I wouldn't expect an uncultured plebe like you" << endl;
        cout << "to know about it." << endl
             << endl;
        cout << "Harumph. You've totally harshed my vibe. Now the school play is" << endl;
        cout << "doomed. DOOMED, I tell you!" << endl
             << endl;
        cout << "You're the worst sister ever! I'm going home and telling mom!\"" << endl;
        this->found = true;
        dropItem();
        cout << "Your sister has stormed off towards home, leaving her sheet lying on the \nground." << endl;
        disappear();
    }
    else
    {
        cout << "Yeah, maybe not the best idea. Who knows what kinds of weirdos hang \nout in graveyards." << endl;
    }
    enterToContinue();

    return 0;
}

bool Sister::getFound()
{
    return found;
}
