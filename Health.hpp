#include "Unit.hpp"

class Health: public Unit {

    int animate = 0;

    public:

        Health(int x, int y);
        void bar();
        bool is_dead();
};