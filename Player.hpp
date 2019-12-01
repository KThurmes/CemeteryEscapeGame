#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Character.hpp"

class Player : public Character
{
private:
    //int health;

public:
    Player();
    ~Player();
    void move();
};

#endif