#pragma once
#include<SDL.h>

class Nest{
SDL_Rect srcRect, moverRect;

public:
    void wiggle(); // wiggle function declared.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    Nest(); Nest(int, int);
};
