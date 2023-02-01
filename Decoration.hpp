#pragma once

#include "Unit.hpp"

class Decoration: public Unit {


    public:
    //Decoration(int x, int y);
    SDL_Rect get_Object();
    virtual void place() = 0;

};