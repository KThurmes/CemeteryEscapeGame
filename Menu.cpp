#include "Menu.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "Game.hpp"
#include "enterToContinue.hpp"
using std::cout;
using std::endl;

Menu::Menu()
{
}

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
        game = new Game();
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
    game->printGameBoard();
    gameLogistics();
    gameOptions();
}

void Menu::gameLogistics()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~Game Logistics~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    cout << "\"x\" marks your spot. You just entered the cemetery through the north" << endl;
    cout << "gate (marked as \"===\" on the map). There are a smattering of" << endl;
    cout << "tombstones (\"n\"), and ghosts (\"G\")." << endl
         << endl;
    cout << "You estimate that you can take about 25 more steps before you succumb"
         << endl;
    cout << " to hunger. " << endl
         << endl;
    cout << "But watch out! The ghosts and their icy glares can sap just as much " << endl;
    cout << "energy from you as your growling stomach. If a ghost is looking in " << endl;
    cout << "your direction (you can tell because the ghosts have an arrow pointing" << endl;
    cout << "in the direction they're turned), quick get out of their way or duck " << endl;
    cout << "behind a tombstone!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
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
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    enterToContinue();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    cout << "You arrive at the cemetery just in time. You hear the gate lock \nautomatically behind you precisely at the moment the sun dips below \nthe horizon. The full moon is shrouded in whispy clouds that cast \neerie shadows on the headstones." << endl
         << endl;
    cout << "You shudder as your mind involuntarily drifts to the stories of \nstrange occurrences that have happened here on nights similar to this." << endl
         << endl;
    cout << "You feel your heart pounding in your chest as a cool breeze jostles \nthe dead leaves clinging to the trees. The shadows begin to stir and \ntake on a life of their own, independent of the wind." << endl
         << endl;
    cout << "No, it's not just your imagination." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    enterToContinue();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    cout << "You know your sister is in here somewhere, but where? You look around \nand see only the phantasmic apparitions that once were confined to \nstories. But no sister." << endl
         << endl;
    cout << "Trying to avoid both the ghosts and their icy glares, you feel \nyourself growing hungrier with every step. Where could she be? And how\nwill you get back out of the cemetery once you find her?" << endl
         << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
    enterToContinue();
}

void Menu::gameOptions()
{
    if (game->getGameOver())
    {
        game->deleteGame();
        delete game;
        startMenu();
    }

    else
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Make a move" << endl;
        cout << "2. View backpack contents" << endl;
        cout << "3. View gameboard key" << endl;
        cout << "4. View player health" << endl;
        cout << "5. Quit" << endl;

        int selection = getNumberBetween(1, 5);

        if (selection == 1)
        {
            game->turn();
            gameOptions();
        }
        else if (selection == 2)
        {
            game->showBackpackContents();
            gameOptions();
        }
        else if (selection == 3)
        {
            game->printBoardKey();
            gameOptions();
        }
        else if (selection == 4)
        {
            game->printPlayerHealth();
            gameOptions();
        }
        else
        {
            game->deleteGame();
            delete game;
        }
    }
}