#pragma once

#include "Decoration.hpp"

class Fire: public Decoration {

    int animate = 0;

    public:

        Fire(int x, int y);
        void place();
};