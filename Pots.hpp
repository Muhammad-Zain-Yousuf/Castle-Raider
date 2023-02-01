#pragma once

#include "Decoration.hpp"

class Pots: public Decoration {

    char kind;

    public:
        Pots(int x, int y, char c);
        void place();
};