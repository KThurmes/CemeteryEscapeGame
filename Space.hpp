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
    int idNum;
    Item *item;
    string spaceType;
    bool spawnGhostEvent;
    bool discovered;
    int row;
    int col;
    bool glare;

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
    void setIDNum(int);
    int getIDNum();
    virtual void interact(Inventory *) = 0;
    void dropItem(Item *);
    Item *pickUpItem();
    bool hasItem();
    string getSpaceType();
    bool getSpawnGhost();
    void setSpawnGhost(bool);
    virtual void changeToDefaultSymbol() = 0;
    void discover();
    void setRowCol(int, int);
    int getRow();
    int getCol();
    void setGlare(bool);
    bool getGlare();
};

#endif