#include "GameBoard.hpp"
#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
#include "Player.hpp"

using std::cout;
using std::endl;

GameBoard::GameBoard()
{
    nCols = 3;
    nRows = 4;
    spaces = new Space **[nRows];

    //initialize spaces
    for (int i = 0; i < nRows; ++i)
    {
        spaces[i] = new Space *[nCols];
        for (int j = 0; j < nCols; ++j)
        {
            spaces[i][j] = new Empty();
        }
    }

    //set spaces' pointers
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            //top row
            if (i - 1 < 0)
            {
                spaces[i][j]->setTop(0);
                spaces[i][j]->setBottom(spaces[i + 1][j]);
            }
            //bottom row
            else if (i + 1 >= nRows)
            {
                spaces[i][j]->setBottom(0);
                spaces[i][j]->setTop(spaces[i - 1][j]);
            }
            //somewhere in the middle
            else
            {
                spaces[i][j]->setTop(spaces[i - 1][j]);
                spaces[i][j]->setBottom(spaces[i + 1][j]);
            }

            //left column
            if (j - 1 < 0)
            {
                spaces[i][j]->setLeft(0);
            }
            //right column
            else if (j + 1 >= nCols)
            {
                spaces[i][j]->setRight(0);
            }
            //somewhere in the middle
            else
            {
                spaces[i][j]->setLeft(spaces[i][j - 1]);
                spaces[i][j]->setRight(spaces[i][j + 1]);
            }
        }
    }
}

/* void GameBoard::setCharacter(int row, int col, Character *charac)
{
    spaces[row][col]->setCharacter(charac);
    spaces[row][col]->setHasCharacter(true);
} */

void GameBoard::printGameBoard()
{
    cout << endl;
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            cout << "-----";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceTop();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceMiddle();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceBottom();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "-----";
        }
        cout << endl;
    }
    cout << endl;
}

void GameBoard::deleteGameBoard()
{
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            delete spaces[i][j];
        }
        delete[] spaces[i];
    }
    delete[] spaces;
}

Space *GameBoard::getSpaceAt(int row, int col)
{
    return spaces[row][col];
}