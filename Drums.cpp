#include "Drums.hpp"

Drums::Drums(int x, int y, char c) {

    x_pos = x;
    y_pos = y;
    kind = c;

    srcRect = {0, 0, 67, 79};
    moverRect = {x_pos, y_pos, 55, 65};
}

void Drums::place() {

    if (kind == '1') srcRect = {202, 114, 67, 79};

    else if (kind == '2') {
        srcRect = {31, 114, 152, 79};
        moverRect = {x_pos, y_pos, 90, 80};
    }

    else if (kind == '3') {
        
        srcRect = {296, 126, 57, 67};
        moverRect = {x_pos, y_pos, 40, 50};
    }

}