#include "Treasure_Gate.hpp"

Treasure_Gate::Treasure_Gate(int x, int y) {

    x_pos = x;
    y_pos = y;

    srcRect = {740, 118, 76, 145};
    moverRect = {x_pos, y_pos, 58, 120};
}

void Treasure_Gate::Open() {

    if (animate == 0) { //For animating the pigeon while flying
        srcRect = {740, 118, 76, 145}; //Change to sprite 1
        animate++; //increment counter

    } else if (animate == 1) {
        srcRect = {837,91,66,172}; //Change to sprite 2
        animate++;
    } else {
        srcRect = {932,92,65,170}; //Change to sprite 3
        animate++; //reset counter
    } 
    
}

SDL_Rect Treasure_Gate::get_TGate() {

    return moverRect;
}

bool Treasure_Gate::Is_Open() {

    if (animate >= 2) {return true;}

    else {return false;}
}