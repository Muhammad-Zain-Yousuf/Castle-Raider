#include "Prototype.hpp"

class Lever: public Prototype {

    int animate = 0;

    public:
        bool escape;
        bool access;
        bool hide;
        Lever();
        bool is_interacted();
        Prototype* clone();
        void toggle();
        SDL_Rect get_item();
};