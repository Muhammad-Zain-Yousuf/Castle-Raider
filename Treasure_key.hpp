#pragma once
#include "Prototype.hpp"

class Treasure_key: public Prototype{
    int move = 0;     //Variable for keeping track and changing of Treasure_key sprite as it flies.

public:
    bool access;
    bool hide;
    bool escape;
    Treasure_key();     //Constructor with parameters x, y for location of Treasure_key on the map.
    void toggle();             // Function declared
    SDL_Rect get_item();
    Prototype* clone();
    bool is_interacted();
};

