#pragma once

#include "Decoration.hpp"

class Drums: public Decoration {

    char kind;

    public:

        Drums(int x, int y, char c);

        void place();
};