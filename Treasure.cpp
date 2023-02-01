#include "Treasure.hpp"
#include<string>
#include<iostream>
#include<vector>


void Treasure::animate_func(){    
    access = true;
    hide = false;
    escape = false;

    if (animate == 0){
        while(animate != 3){
            if (animate == 0) { //For animating the treasure box to close
                    srcRect = {258,519,77,60};  //3
                } else if (animate == 1) {
                    srcRect = {150,522,77,60};  //2
                } else{
                    srcRect = {38,525,77,60};   //1
                } 
            animate++;
        }
    } 
    // else {
    //     while(animate != 3){
    //         if (animate == 0) { //For animating the treasure box to open
    //                 srcRect = {38,525,77,60};  //1        
    //             } else if (animate == 1) {
    //                 srcRect = {378,522,77,60}; //2
    //             } else if (animate == 2) {
    //                 srcRect = {486,519,77,60}; //3
    //             } 
    //         animate++;
    //     }
} 

void Treasure::toggle(){   //Fly function for detecting whether Treasure has been opened.

        if (move == 0) {                  //Condition for untouched treasure.
            srcRect = {486,519,77,60};     //src for sprite of filled treasure
            Treasure::animate_func();
            move+=1;
                           //increment counter
        } else{         //Condition for untouched treasure.
            srcRect = {38,525,77,58};   //src for sprite of empty treasure
            Treasure::animate_func();
            
            // toggle=0;               //reset counter
        }

        
    }

bool Treasure::is_interacted() {

    if (move > 0) {
        return true;
    }
    else {
        return false;
    }
}

Treasure::Treasure() {     //Constructor fed with parameters x, y for location of Treasure.
        // x_pos = x;
        // y_pos = y;
        srcRect = {486,519,77,60};  // Default sprite for open treasure
        moverRect = {880, 195, 60, 45}; //set Treasure at x_pos, y_pos on screen with size 60,45

        // Sprites co-ordinates for Filled Treasure Chest:
        // Treasurechest_1 srcRect = {38,525,77,60};    -> closed treasure chest 
        // Treasurechest_2 srcRect = {378,522,77,60};   -> partially opened treasure chest 
        // Treasurechest_3 srcRect = {486,519,77,60};   -> opened treasure chest

        // Sprites co-ordinates for Empty Treasure Chest:
        // Treasurechest_1 srcRect = {38,525,77,60};    -> closed treasure chest 
        // Treasurechest_2 srcRect = {150,522,77,60};   -> partially opened treasure chest 
        // Treasurechest_3 srcRect = {258,519,77,60};   -> opened treasure chest
    }

SDL_Rect Treasure::get_item() {

    return moverRect;
}

Prototype* Treasure::clone() {

    return new Treasure();
}