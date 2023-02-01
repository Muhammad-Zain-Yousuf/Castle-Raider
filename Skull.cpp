#include "Skull.hpp"

Skull::Skull(int x, int y) {

    x_pos = x;
    y_pos = y;
    srcRect = {551, 238, 63, 53};
    moverRect = {x_pos, y_pos, 50, 40};
}

void Skull::place() {
    srcRect = {551, 238, 63, 53};
}



