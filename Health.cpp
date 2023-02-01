#include "Health.hpp"

Health::Health(int x, int y) {

    x_pos = x;
    y_pos = y;

    srcRect = {770, 1030, 96, 29};
    moverRect = {x_pos, y_pos, 150, 50};
}


void Health::bar() {

    if (animate >= 0 && animate < 6) {
        srcRect = {770, 1030, 96, 29};
        animate++;
    }

    else if (animate >= 6 && animate < 11) {
        srcRect = {772, 1082, 93, 25};
        animate++;
    }

    else if (animate >= 11 && animate < 16) {
        srcRect = {772, 1124, 93, 25};
        animate++;
    }

    else if (animate >= 16 && animate < 21) {
        srcRect = {773, 1169, 93, 25};
        //animate++;
    }
}

bool Health::is_dead() {

    if (animate >= 16 && animate < 21) {return true;}

    else {return false;}
}