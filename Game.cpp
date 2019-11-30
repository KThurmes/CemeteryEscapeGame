#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

Game::Game()
{
    gb = new GameBoard();
    Player *play = new Player();
    gb->setCharacter(0, 0, play);
}

void Game::printGameBoard()
{
    gb->printGameBoard();
}