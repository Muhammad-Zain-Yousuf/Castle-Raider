#include "Pots.hpp"

Pots::Pots(int x, int y, char c) {

    x_pos = x;
    y_pos = y;
    kind = c;

    srcRect = {1138, 389, 53, 67};
    moverRect = {x_pos, y_pos, 40, 50};
}

void Pots::place() {

    if (kind == '1') srcRect = {1138, 300, 53, 66};

    else if (kind == '2') srcRect = {1138, 389, 53, 67};
    

}