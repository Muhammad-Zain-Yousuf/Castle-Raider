#pragma once
#include "Prototype.hpp"

class Spikes: public Prototype{
    int move = 0; //Variable for keeping track and changing of Spikes sprite as it flies.

public:
    void toggle(); 
    bool access;
    bool hide;
    bool escape;
    Spikes(); //Default values set for creation of Spikes at bottom left corner, only kept for debugging purposes.
    bool is_interacted();
    SDL_Rect get_item();
    Prototype* clone();
};
