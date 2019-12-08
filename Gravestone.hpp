#ifndef GRAVESTONE_HPP
#define GRAVESTONE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
#include <string>
using std::string;
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
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    void interact(Inventory *);
    void setHasKey(bool);
    void changeToDefaultSymbol();
    void setEngraving(string);
};
#endif