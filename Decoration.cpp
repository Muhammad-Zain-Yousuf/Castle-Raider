#include "Decoration.hpp"

    SDL_Rect Decoration::get_Object(){
        return moverRect;
    }
// Decoration::Decoration(int x, int y) {

//     x_pos = x;
//     y_pos = y;

//     // srcRect = {454, 118, 44, 86};
//     // moverRect = {x, y, 35, 60};
// }


// void Decoration::fire(int x, int y) {

//     srcRect = {454, 118, 44, 86};
//     moverRect = {x, y, 35, 60};

//     if (animate == 0) { //For animating the pigeon while flying
//         srcRect = {454,118,44,86}; //Change to sprite 1
//         animate += 1; //increment counter

//     } else if (animate == 1) {
//         srcRect = {512,118,45,86}; //Change to sprite 2
//         animate += 1;
//     } else if (animate == 2) {
//         srcRect = {571,118,45,86}; //Change to sprite 3
//         animate += 1; //reset counter
//     } else {
//         srcRect = {631, 118, 45, 86};
//         animate = 0;
//     }
// }



// void Decoration::skulls(int x, int y) {
    
//     srcRect = {551, 238, 63, 53};
//     moverRect = {x, y, 30, 30};

//     srcRect = {551, 238, 63, 53};
//     moverRect = {50, 10, 30, 30};
// }

// void Decoration::pots_drums() {

//     srcRect = {202, 114, 67, 79};
//     moverRect = {450, 100, 30, 30};

//     srcRect = {31, 114, 152, 79};
//     moverRect = {700, 400, 30, 30};

//     srcRect = {296, 126, 57, 67};
//     moverRect = {100, 500, 30, 30};

// }