#pragma once
#include "Unit.hpp"

class Prototype: public Unit {

    
    public:

        virtual Prototype* clone() = 0;
        virtual void toggle() = 0;
        virtual SDL_Rect get_item() = 0;
        virtual bool is_interacted() = 0;
        bool access = false;
        bool hide = false;
        bool escape = false;
};