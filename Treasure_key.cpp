#include "Treasure_key.hpp"
#include<string>
#include<iostream>
#include<vector>


void Treasure_key::toggle(){ //Fly function for moving Treasure_key as tasked in manual
        
        //Debugging
        //std::cout<<"Toggle = "<<toggle<<std::endl;        

        // if (toggle == 0) { 
        //     srcRect = {427,244,43,42}; //Change to Treasure_key On sprite 
        //     toggle+=1;
        // } else if (toggle == 1) {
        //     srcRect = {476,245,43,42}; //Change to Treasure_key Off sprite 
        //     toggle=0; //reset counter
        // }
        srcRect = {0,0,1,2};
        hide = true;
        access = false;
        escape = false;
    }



Treasure_key::Treasure_key() { //Constructor with parameters x, y for initial location of Treasure_key.
        // x_pos = x;
        // y_pos = y;
        srcRect = {427,244,43,42};  //Default sprite-> golden key
        moverRect = {190, 440, 30, 30}; //set Treasure_key at x_pos, y_pos on screen with size 30,30
        //Sprites co-ordinates for Treasure_keys
        // Treasure_keyShow srcRect = {427,244,43,42};
        // Treasure_keyHide srcRect = {476,245,43,42};
    }

SDL_Rect Treasure_key::get_item() {

    return moverRect;
}

Prototype* Treasure_key::clone() {

    return new Treasure_key();
}

bool Treasure_key::is_interacted() {

    return false;
}