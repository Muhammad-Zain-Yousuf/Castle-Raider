#include "Unit.hpp"

class Main_Gate: public Unit {

    int animate = 0;

    public:

    Main_Gate(int x, int y);
    void Open();
    bool is_open();
    SDL_Rect get_main();
};