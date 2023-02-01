#pragma once
#include "Unit.hpp"

class Player: public Unit {
   
    int mov_up=0;
    int mov_down=0;
    int mov_left=0;
    int mov_right=0;
    
    static Player* instance;
    Player() {

        srcRect = {421,889,85,90};  //Default sprite 1 -> set as off by default
        moverRect = {740, 490, 50, 50}; //set Player at x_pos, y_pos on screen with size 40,40

    }

    public:
    
    //Player(int, int); //Default values set for creation of Treasure at bottom left corner, only kept for debugging purposes.
    static Player* getInstance();

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    SDL_Rect getPosition();
    bool wall_collision(char d);

    
};