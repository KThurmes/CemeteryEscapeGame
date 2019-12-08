#ifndef GRAVESTONE_HPP
#define GRAVESTONE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
class Gravestone : public Space
{
private:
    bool knockedOver;
    bool hasKey;
    bool cleaned;
    string engraving;

public:
    Gravestone();
    ~Gravestone();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    void interact(Inventory *);
    void setHasKey(bool);
    void changeToDefaultSymbol();
    void setEngraving(string);
};
#endif