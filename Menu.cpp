#include "Menu.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "Game.hpp"
using std::cout;
using std::endl;

void Menu::welcome()
{
    cout << "Welcome!" << endl;
    startMenu();
}

void Menu::startMenu()
{
    cout << "Would you like to start a new game?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        launchGame();
    }
    else
    {
        cout << "Goodbye!" << endl;
    }
}

void Menu::launchGame()
{
    backstory();
    game.printGameBoard();
    gameOptions();
}

void Menu::backstory()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "Background";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << endl
         << endl;
    cout << "It's getting dark and your mom has asked you to go out to find your\nsister and bring her home for dinner." << endl
         << endl;
    cout << "Your sister had told your mom she was going to be practicing for the\nschool play at her friend's house, but when you arrived at the \nfriend's house, she wasn't there. The friend told you that your sister\nhad last been seen ducking into the graveyard on her walk home from\nschool." << endl
         << endl;
    cout << "Sigh. What a pest." << endl
         << endl;
    cout << "But the sun is setting and dinner is on the table, so you grab your\nbackpack and head over to the cemetary." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~"
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
}

void Menu::gameOptions()
{
    cout << "What would you like to do?" << endl;
    cout << "1. Make a move" << endl;
    cout << "2. View backpack contents" << endl;
    cout << "3. View gameboard key" << endl;
    cout << "4. View player health" << endl;
    cout << "5. Quit" << endl;

    int selection = getNumberBetween(1, 4);

    if (selection == 1)
    {
        if (!game.checkGameOver())
        {
            game.turn();
            gameOptions();
        }
    }
    else if (selection == 2)
    {
        game.showBackpackContents();
        gameOptions();
    }
    else if (selection == 3)
    {
        gameOptions();
    }
    else
    {
        game.deleteGame();
    }
}