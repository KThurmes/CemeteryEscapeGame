#ifndef GATE_HPP
#define GATE_HPP
#include "Space.hpp"
class Gate : public Space
{
private:
    bool gateOpened;

public:
    Gate();
    ~Gate();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
};
#endif