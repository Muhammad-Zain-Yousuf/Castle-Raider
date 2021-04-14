#include "Main_Gate.hpp"

Main_Gate::Main_Gate(int x = 500, int y = 100) {

    x_pos = x;
    y_pos = y;

    srcRect = {0,0,112,34};
    moverRect = {x, y, 50, 50};

}

void Main_Gate::Open() {


    if (animate == 0) { //For animating the pigeon while flying
        srcRect = {0,0,160,133}; //Change to sprite 1
        animate += 1; //increment counter

    } else if (animate == 1) {
        srcRect = {0,141,151,146}; //Change to sprite 2
        animate += 1;
    } else {
        srcRect = {0,278,160,411}; //Change to sprite 3
        animate = 0; //reset counter
    }

}