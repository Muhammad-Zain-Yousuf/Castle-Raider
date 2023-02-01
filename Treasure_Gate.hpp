#include "Unit.hpp"

class Treasure_Gate: public Unit {

    int animate = 0;

    public:

    Treasure_Gate(int x, int y);
    void Open();
    bool Is_Open();
    SDL_Rect get_TGate();
    
};