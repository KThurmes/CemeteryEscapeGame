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
    bool playerHasSheet;
    bool playerHasKey;
    bool gameOver;

public:
    Game();
    void printGameBoard();
    void deleteGame();
    void turn();
    void interaction(Space *);
    void showBackpackContents();
    void printBoardKey();
    void spawnGhost(int, int);
    void spawnGhost(Space *);
    bool checkGameOver();
    void printPlayerHealth();
    void moveCharacter(Character *, Space *);
    void moveCharacter(Character *, int, int);
    bool getGameOver() { return gameOver; };
    string buildPrintString();
    int stringPosition(int, int, int);
    void checkGlareHit();
    void setGlares();
};
#endif