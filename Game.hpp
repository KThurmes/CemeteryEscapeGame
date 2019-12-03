#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Space.hpp"
#include "Sister.hpp"
#include "Character.hpp"

class Game
{
private:
    Player player;
    Sister sister;
    GameBoard gb;
    bool gameOver;
    Character *charList;
    bool playerHasSheet;
    bool playerHasKey;

public:
    Game();
    void printGameBoard();
    void deleteGame();
    void turn();
    void setPlayer(int, int);
    void setSister(int, int);
    void setCharacter(Character *, int, int);
    void interaction(Space*);
    void interactionCheck();


};
#endif