#ifndef MENU_HPP
#define MENU_HPP
#include "Game.hpp"

class Menu
{
private:
    Game game;

public:
    void welcome();
    void startMenu();
    void launchGame();
    void backstory();
    void gameOptions();
};

#endif