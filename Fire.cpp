#include "fire.hpp"

Fire::Fire(int x, int y) {

    x_pos = x;
    y_pos = y;

    srcRect = {454, 118, 44, 86};
    moverRect = {x_pos, y_pos, 35, 60};
}

void Fire::place() {

    if (animate == 0) { //For animating the pigeon while flying
        srcRect = {454,118,44,86}; //Change to sprite 1
        animate += 1; //increment counter

    } else if (animate == 1) {
        srcRect = {512,118,45,86}; //Change to sprite 2
        animate += 1;
    } else if (animate == 2) {
        srcRect = {571,118,45,86}; //Change to sprite 3
        animate += 1; //reset counter
    } else {
        srcRect = {631, 118, 45, 86};
        animate = 0;
    }
}