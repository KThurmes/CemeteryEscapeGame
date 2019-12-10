/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Space is a parent class describing a space in the game 
board. It contains pointers to its four neighboring Spaces, an Item, a 
bool for whether there is a character on the space or not, whether the 
sSpace is passable by a Character or not, whether it is being hit with 
a NPC's glare or not, whether it has a key or not. It also has a flag 
for spawning a new Ghost. It contains strings to describe what kind of 
space it is and to store the print symbol of the space. There are also 
ints to describe where in the gameBoard grid the Space is.

The methods in this Class are primarily getters and setters. 
Essentially, the only non-trivial method is pickUpItem(), which is 
functionally a "getter" but it also sets the item member to null 
before returning the Item that used to be the Space's item.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Item.hpp"
#include "Inventory.hpp"
using std::string;

class Space
{
protected:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    bool hasCharacter;
    bool passable;
    string printSymbol;
    Item *item;
    string spaceType;
    bool spawnGhostEvent;
    int row;
    int col;
    bool glare;
    bool hasKey;

public:
    Space();
    virtual string printSpaceTop() = 0;
    virtual string printSpaceMiddle() = 0;
    virtual string printSpaceBottom() = 0;
    virtual ~Space(){};
    void setTop(Space *);
    void setRight(Space *);
    void setBottom(Space *);
    void setLeft(Space *);
    void setHasCharacter(bool);
    Space *getTop();
    Space *getRight();
    Space *getBottom();
    Space *getLeft();
    bool getPassable();
    bool getHasCharacter();
    virtual void interact(Inventory *) = 0;
    void dropItem(Item *);
    Item *pickUpItem();
    bool hasItem();
    string getSpaceType();
    bool getSpawnGhost();
    void setSpawnGhost(bool);
    void setRowCol(int, int);
    int getRow();
    int getCol();
    void setGlare(bool);
    bool getGlare();
    bool getHasKey();
    void setHasKey(bool);
};

#endif