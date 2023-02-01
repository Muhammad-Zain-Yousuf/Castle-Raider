#pragma once
#include "Unit.hpp"

class Guard: public Unit{
    int n2 = 255;    //moverRect.y 
    int n1 = 485;   //positions
    int n3 = 645;    
    int n4 = 405;  //moverRect.x positions
    int animate =  0;
    int animate1 =  0;
    int animate2 =  0;
    int turn = 0;
    

public:
    
    Guard(int x, int y); //
    void patrol();
    SDL_Rect get_guard();
    
};