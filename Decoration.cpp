#include "Decoration.hpp"

void Decoration::fire() {

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

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


void Decoration::pond() {

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

}

void Decoration::skulls() {
    
    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};
}

void Decoration::pots_drums() {

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

    srcRect = {0, 0, 123, 45};
    moverRect = {50, 10, 30, 30};

}