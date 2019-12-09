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