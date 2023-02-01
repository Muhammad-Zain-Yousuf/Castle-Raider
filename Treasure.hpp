#pragma once
#include "Prototype.hpp"

class Treasure: public Prototype {
    int move = 0;   // Variable for keeping track and changing of Treasure sprite
    int animate = 0; // Variable for the animation of opening and closing the treasure chest.

public:
    bool access;
    bool hide;
    bool escape;
    Treasure(); //Constructor with parameters x, y for the location of Treasure on the map.
    Prototype* clone();
    void toggle();          // Decleration of Treasure's 
    void animate_func();        // functions
    bool is_interacted();
    SDL_Rect get_item();
};
