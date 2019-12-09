#ifndef GATE_HPP
#define GATE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
#include <string>
using std::string;
class Gate : public Space
{
private:
public:
    Gate();
    ~Gate();
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    void interact(Inventory *);
};
#endif