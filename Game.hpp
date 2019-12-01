#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Space.hpp"

class Game
{
private:
    Player player;
    GameBoard gb;
    bool gameOver;
    Character *charList;

public:
    Game();
    void printGameBoard();
    void deleteGame();
    void turn();
    void setPlayer(int, int);
};
#endif