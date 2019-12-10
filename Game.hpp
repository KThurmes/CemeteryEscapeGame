/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Game is the main driver for the entire game. It 
keeps all the objects relating to game play together in one place.

Data members: player and sister objects, a gameboard, a list of all 
non-playable characters that appear in the game (NPCList), a list of 
all items that appear in the game (itemList), and a bool that will 
flag that the game is over.

Methods: Game has public methods to print the game board 
(printGameBoard), delete itself (deleteGame), run through one turn 
(turn), show the contents of the player's backpack 
(showBackpackContents), print a key that explains the symbols on the 
board (printBoardKey), and prints the player's health 
(printPlayerHealth).
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Space.hpp"
#include "Sister.hpp"
#include "Character.hpp"
#include "Item.hpp"
#include "NPC.hpp"
#include <string>
#include <list>
using std::list;
using std::string;

class Game
{
private:
    Player player;
    Sister sister;
    GameBoard gb;
    list<NPC *> NPCList;
    list<Item *> itemList;
    bool gameOver;

    void interaction(Space *);
    void spawnGhost(int, int);
    void spawnGhost(Space *);
    bool checkGameOver();
    void moveCharacter(Character *, Space *);
    void moveCharacter(Character *, int, int);
    string buildPrintString();
    int stringPosition(int, int, int);
    int checkGlareHit();
    void setGlares();
    void snackDrop(NPC *);

public:
    Game();
    bool getGameOver() { return gameOver; };
    void printGameBoard();
    void deleteGame();
    void turn();
    void showBackpackContents();
    void printBoardKey();
    void printPlayerHealth();
};
#endif