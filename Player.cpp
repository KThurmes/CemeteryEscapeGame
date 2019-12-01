#include "Player.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Player::Player()
{
    location = 0;
    symbol = 'x';
}

Player::~Player()
{
}

void Player::move()
{
    cout << "In which direction would you like your player to go?" << endl;
    cout << "0: Up" << endl;
    cout << "1: Right" << endl;
    cout << "2: Down" << endl;
    cout << "3: Left" << endl;
    cout << "4: Don't move" << endl;

    int selection = getNumberBetween(0, 4);

    Space *destination;

    cout << "Player is on tile " << location->getIDNum() << endl;
    if (selection == 0)
    {
        //check up
        destination = location->getTop();
    }

    else if (selection == 1)
    {
        //check right
        destination = location->getRight();
    }

    else if (selection == 2)
    {
        //check down
        destination = location->getBottom();
    }

    else if (selection == 3)
    {
        //check left
        destination = location->getLeft();
    }
    else
    {
        return;
    }

    if (destination != 0)
    {
        cout << "Destination is tile " << destination->getIDNum() << endl;
        //Make sure the space is passable
        if (!destination->getPassable())
        {
            destination->interact();
        }
        //Make sure there isn't a character there already
        else if (destination->getHasCharacter())
        {
            cout << "There's another character there!" << endl;
            move();
        }
        else
        {
            setLocation(destination);
        }
    }
    else
    {
        cout << "Cannot go in that direction!" << endl;
        move();
    }
}