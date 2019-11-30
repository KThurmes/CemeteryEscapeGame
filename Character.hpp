#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/* enum direction
{
    Up = 0,
    Right = 1,
    Down = 2,
    Left = 3
}; */

class Character
{
protected:
    char symbol;

public:
    virtual void move() = 0;
    char getSymbol();
};

#endif