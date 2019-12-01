#include "NPC.hpp"
#include "Space.hpp"

void NPC::turn(int direction){
    //0 is clockwise rotation, 1 is counter-clockwise
    if (direction == 0){
        direction = (direction + 1) % 4;
    }
    //counter-clockwise
    else{
        direction = (direction + 3) % 4;
    }
}

void NPC::step(){
    //move to the next square according to which direction the character is facing.
    Space* destination;
    
    if (direction == 0){
        destination = location->getTop();
    }
    else if(direction == 1){
        destination = location->getRight();
    }
    else if (direction == 2){
        destination = location->getBottom();
    }
    else{
        destination = location->getLeft();
    }

    //Make sure there isn't anything in the way
    if (destination != 0){
        if(!destination->getHasCharacter()){
            if(destination->getPassable()){
                setLocation(destination);
            }
        }
    }
}