#include "Unit.hpp"

class Treasure_Gate: public Unit {

    int animate = 0;

    public:

    Treasure_Gate(int x, int y): x_pos(x), y_pos(y) {}
    void Open();
    
};