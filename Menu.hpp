/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Menu initializes the game and allows the user to 
select what to do after each round.
********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include "Game.hpp"

class Menu
{
private:
    Game *game;

public:
    Menu();
    void welcome();
    void startMenu();
    void launchGame();
    void backstory();
    void gameOptions();
    void gameInfoMenu();
    void gameLogistics();
};

#endif