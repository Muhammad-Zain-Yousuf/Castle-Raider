#include "Lever.hpp"

Lever::Lever() {

    // x_pos = x;
    // y_pos = y;

    srcRect = {966, 539, 89, 48};
    moverRect = {360, 170, 75, 45};
}

void Lever::toggle() {
    escape = true;
    access = false;
    hide = false;

    if (animate == 0) { 
        srcRect = {966, 539, 89, 48}; //Change to sprite 1
        moverRect = {360, 170, 75, 45};
        animate += 1; //increment counter

    } else if (animate == 1) {
        srcRect = {870,516,60,71}; //Change to sprite 2
        moverRect = {365, 150, 50, 65};
        animate += 1;
    } else if (animate == 2) {
        srcRect = {772,515,60,71}; //Change to sprite 3
        moverRect = {357, 149, 50, 65};
        animate += 1; //reset counter
    } else {
        srcRect = {647, 539, 89, 47};
        moverRect = {337, 170, 75, 45};
        // animate = 0;
    }

}

SDL_Rect Lever::get_item() {

    return moverRect;
}

Prototype* Lever::clone() {

    return new Lever();
}

bool Lever::is_interacted() {

    return false;
}