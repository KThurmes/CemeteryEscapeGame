#include "GameBoard.hpp"
#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
#include "Player.hpp"
#include "Gate.hpp"
#include "Fence.hpp"
#include "Gravestone.hpp"
#include "Key.hpp"

using std::cout;
using std::endl;

GameBoard::GameBoard()
{
    nCols = 14;
    nRows = 7;
    spaces = new Space **[nRows];
    int k = 0;

    //initialize spaces
    for (int i = 0; i < nRows; ++i)
    {
        spaces[i] = new Space *[nCols];
        for (int j = 0; j < nCols; ++j)
        {
            //Create the fence and gate
            if (i == 0)
            {
                if (j == 7)
                {

                    spaces[i][j] = new Gate();
                }
                else
                {
                    spaces[i][j] = new Fence();
                }
            }
            //Place gravestones
            else if (i == 1 && j == 2)
            {
                spaces[i][j] = new Gravestone();
            }
            else if (i == 5 && j == 3)
            {
                spaces[i][j] = new Gravestone();
            }
            else if (i == 5 && j == 8)
            {
                spaces[i][j] = new Gravestone();
            }
            else if (i == 1 && j == 9)
            {
                spaces[i][j] = new Gravestone();
            }
            //This last one has the key.
            else if (i == 6 && j == 8)
            {
                Gravestone *grave = new Gravestone();
                grave->setHasKey(true);
                spaces[i][j] = grave;
            }

            //Fill in every other square
            else
            {
                spaces[i][j] = new Empty();
                spaces[i][j]->setIDNum(k);
            }
            ++k;
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
                spaces[i][j]->setRight(spaces[i][j + 1]);
            }
            //right column
            else if (j + 1 >= nCols)
            {
                spaces[i][j]->setRight(0);
                spaces[i][j]->setLeft(spaces[i][j - 1]);
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

string GameBoard::printGameBoard()
{
    string boardVis = "\n";
    cout << endl;
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "-----";
            cout << "-----";
        }
        cout << endl;
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            boardVis += "|";
            //spaces[i][j]->printSpaceTop();
            boardVis += spaces[i][j]->printSpaceTop();
            cout << "|";
            boardVis += "|";
        }
        cout << endl;
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            boardVis += "|";
            boardVis += spaces[i][j]->printSpaceMiddle();
            cout << "|";
            boardVis += "|";
        }
        cout << endl;
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            boardVis += "|";
            boardVis += spaces[i][j]->printSpaceBottom();
            cout << "|";
            boardVis += "|";
        }
        cout << endl;
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            cout << "-----";
            boardVis += "-----";
        }
        cout << endl;
        boardVis += "\n";
    }
    cout << endl;
    boardVis += "\n";
    return boardVis;
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

void GameBoard::printKey()
{
    cout << endl
         << endl;
    cout << "|, --";
    cout << "        ";
    cout << "Space boundaries" << endl;
    cout << "X";
    cout << "            ";
    cout << "Player location" << endl;
    cout << "---";
    cout << "          ";
    cout << "Fence" << endl;
    cout << "===";
    cout << "          ";
    cout << "Gate" << endl;
    cout << "±";
    cout << "            ";
    cout << "Gravestone";
    cout << "#";
    cout << "            ";
    cout << "Item";
    cout << "G";
    cout << "            ";
    cout << "Ghost";
    cout << "g";
    cout << "            ";
    cout << "???";
    cout << endl
         << endl;
}

int GameBoard::getNRows()
{
    return nRows;
}

int GameBoard::getNCols()
{
    return nCols;
}