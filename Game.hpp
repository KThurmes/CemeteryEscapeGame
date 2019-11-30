#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "GameBoard.hpp"

class Game
{
private:
    Player *player;
    GameBoard *gb;
    bool gameOver;

public:
    Game();
    void printGameBoard();
};
#endif