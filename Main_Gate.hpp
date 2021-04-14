#include "Unit.hpp"

class Main_Gate: public Unit {

    int animate = 0;

    public:

    Main_Gate(int x, int y): x_pos(x), y_pos(y) {}
    void Open();
};