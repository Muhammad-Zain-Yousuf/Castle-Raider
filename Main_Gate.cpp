#include "Main_Gate.hpp"

Main_Gate::Main_Gate(int x, int y) {

    x_pos = x;
    y_pos = y;

    srcRect = {570,316,154,157};
    moverRect = {x, y, 120, 120};

}

void Main_Gate::Open() {


    if (animate == 0) { //For animating the pigeon while flying
        srcRect = {570,316,154,157}; //Change to sprite 1
        animate += 1; //increment counter

    } else if (animate == 1) {
        srcRect = {756,302,154,171}; //Change to sprite 2
        animate += 1;
    } else {
        srcRect = {937,301,161,171}; //Change to sprite 3
        //animate = 0; //reset counter
    }

}

SDL_Rect Main_Gate::get_main() {

    return moverRect;
}

bool Main_Gate::is_open() {

    if (animate == 2) {return true;}

    else {return false;}
}