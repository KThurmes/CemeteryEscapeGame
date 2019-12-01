#include "Player.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Player::Player()
{
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

    if (selection == 0)
    {
        //check up
        //move
    }

    else if (selection == 1)
    {
        //check right
        //move
    }

    else if (selection == 2)
    {
        //check down
        //move
    }

    else if (selection == 3)
    {
        //check left
        //move
    }
}