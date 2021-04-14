#include "Unit.hpp"
#include<SDL.h>

// Draw function to be inherited by all the rest of the classes!

void Unit::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);

}