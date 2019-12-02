#include "Sister.hpp"
#include "getRandomInt.hpp"
#include "Character.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
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

int Sister::interact(){
    cout<< "Hm. This ghost looks odd. Upon further inspection, it looks like it might just be a person walking around in a white bedsheet."<<endl;
    cout<< "Pull the sheet?"<<endl;
    cout<< "1. Yes"<<endl;
    cout <<"2. No" <<endl;
    int selection = getNumberBetween(1,2);
    if (selection ==1){
        cout<< "Sister: \"Excuse me! I was practicing for Hamlet. It's called \"method acting\" and I wouldn't expect an uncultured plebe like you to know about it."<<endl;
        cout<< "Harumph. You've totally harshed my vibe. Now the school play is doomed. DOOMED, I tell you!"<<endl;
        cout<< "You're the worst sister ever! I'm going home and telling mom!"<<endl;
        this->found = true;
        disappear();
    }
    else {
        cout<< "Yeah, maybe not the best idea. Who knows what kinds of weirdos hang out in graveyards."<<endl;
    }

    return 0;
}

bool Sister::getFound()
{
    return found;
    }

