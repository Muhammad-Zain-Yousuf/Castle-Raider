#include "Spikes.hpp"
#include<string>
#include<iostream>
#include<vector>

void Spikes::toggle(){ //Fly function for moving Spikes as tasked in manual
        
        //Debugging
        //std::cout<<"Toggle = "<<toggle<<std::endl;        

        if (move >= 0 && move < 20) { //For animating the Spikes while flying
            srcRect = {997,133,76,78}; //Change to Spikes On sprite 
            move+=1; //increment counter
        } else if (move >= 20 && move < 41)  {
            srcRect = {1087,134,76,78}; //Change to Spikes Off sprite 
            move++;
        }

        else {

            move=0; //reset counter
        }

        access = false;
        hide = false;
        escape = false;
    }

bool Spikes::is_interacted() {

    if (move >= 20 && move < 41) {
        return true;

    }

    else
    {
        return false;
    }
    
}

SDL_Rect Spikes::get_item() {

    return moverRect;
}

Spikes::Spikes() { //Constructor with parameters x, y for initial location of Spikes.
        // x_pos = x;
        // y_pos = y;
        srcRect = {1087,134,76,78};  //Default sprite 1 -> set as off by default
        moverRect = {290, 480, 60, 60}; //set Spikes at x_pos, y_pos on screen with size 50,60
        // Sprites co-ordinates for Spikess
        // SpikesOn srcRect = {997,133,1075,212};
        // SpikesOff srcRect = {1087,134,1163,212};
        
    }

Prototype* Spikes::clone() {

    return new Spikes();
}