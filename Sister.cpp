#include "Sister.hpp"
#include "getRandomInt.hpp"
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;


Sister::Sister(){

    location = 0;
    symbol = "S";
}

Sister::~Sister(){

}

void Sister::move(){
    //Randomly choose to turn or step
    int moveOption = getRandomInt(0,1);

    //turn
    if(moveOption == 0){
        //choose to turn right or left
        moveOption = getRandomInt(0,1);
        turn(moveOption);
    }
    //step forward
    else if (moveOption == 1){
        step();
    }
    else{
        //something went wrong
    }

}