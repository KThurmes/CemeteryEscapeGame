#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Space.hpp"

class Empty : public Space
{
private:
public:
    Empty();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    ~Empty();
    void interact(Inventory *);
    void changeToDefaultSymbol();
};
#endif