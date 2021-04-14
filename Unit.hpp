#pragma once
#include<SDL.h>

class Unit {

    protected:

        SDL_Rect srcRect, moverRect;    // SDL_Rect attributes
        int x_pos, y_pos;               // Variables for objects' positions

    public:

        void draw(SDL_Renderer*, SDL_Texture* assets); //Draw function declaration

};