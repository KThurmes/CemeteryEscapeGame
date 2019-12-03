#ifndef GATE_HPP
#define GATE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
class Gate : public Space
{
private:
public:
    Gate();
    ~Gate();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    void interact(Inventory *);
    void changeToDefaultSymbol();
};
#endif