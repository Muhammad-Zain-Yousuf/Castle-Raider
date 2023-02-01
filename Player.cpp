#include "Player.hpp"
#include<string>
#include<iostream>


int mov_up;
int mov_down;
int mov_left;
int mov_right;

SDL_Rect Player::getPosition() {
    //return SDL_Rect = {x_pos, y_pos, 0, 0};
    return moverRect;
}

/**
 * This function is for detecting player collision with map walls. 
 * The map is divided into regions, such that the inaccessible regions of the map 
 * are hard coded in this function using co-ordinates to detect collision and prevent
 * player from moving into the walls.
 * \param d is the direction in which collision is checked.
 */

bool Player::wall_collision(char d){
    int increment = 6;
    int width = 50;
    int height = 50;
    if (d == 'U'){
        //Region 1 and 6
        if ((0-width <= moverRect.x && moverRect.x <= 470) || (587-width <= moverRect.x && moverRect.x <= 1000)){
            if (184 - (height - 10) <= moverRect.y && moverRect.y <= 244 ) {
                if ((moverRect.y - increment) < 184 - (height - 10)) {
                    return true;
                }
            }
        }
        //Region 2 and 7
        if ((0-width <= moverRect.x && moverRect.x <= 352) || (706-width <= moverRect.x && moverRect.x <= 881)){
            if (419 - (height - 10) <= moverRect.y && moverRect.y <= 482 ) {
                if ((moverRect.y - increment) < 419 - (height - 10)) {
                    return true;
                }
            }
        }
        //Region 10
        if (293-width <= moverRect.x && moverRect.x <= 352){
            if (483 - (height - 10) <= moverRect.y && moverRect.y <= 539 - (height - 10)) {
                if ((moverRect.y - increment) < 483 - (height - 10)) {
                    return true;
                }
            }
        }
        return false;

    } else if (d == 'D'){

        //Region 3 and 5
        if ((0-width <= moverRect.x && moverRect.x <= 705) || (820-width <= moverRect.x && moverRect.x <= 1000)){
            if (486 <= moverRect.y && moverRect.y <= 539) {
                if ((moverRect.y + height + increment) > 539) {
                    return true;
                }
            }
        }
        //Region 2 and 7
        if ((0-width <= moverRect.x && moverRect.x <= 352) || (708-width <= moverRect.x && moverRect.x <= 881)){
            if (185 <= moverRect.y && moverRect.y <= 246) {
                if ((moverRect.y + height + increment) > 246) {
                    return true;
                }
            }
        }

        //Region 13
        if (706-width <= moverRect.x && moverRect.x <= 819) {
            if (500 <= moverRect.y && moverRect.y <= 592) {
                if ((moverRect.y + height + increment) > 592) {
                    return true;
                }
            }
        }

        //Region Water
        if (467-width <= moverRect.x && moverRect.x <= 589) {
            if (347 <= moverRect.y && moverRect.y <= 377) {
                if ((moverRect.y + height + increment) > 422) {
                    return true;
                }
            }
        }

        return false;
        
    } else if (d == 'L'){
        //Regions 1,8,2,9,10,3,7,11

        //Region 1
        if (0 <= moverRect.y && moverRect.y <= 184 - (height - 10)) {
            if (420 <= moverRect.x && moverRect.x <= 505) {
                if ((moverRect.x - increment) < 470) {
                    return true;
                }
            }
        }

        //Region 2
        if (206 <= moverRect.y && moverRect.y <= 379) {
            if (352 <= moverRect.x && moverRect.x <= 427) {
                if ((moverRect.x - increment) < 352) {
                    return true;
                }
            }
        }

        //Region 3
        
        if (499 <= moverRect.y && moverRect.y <= 560) {
            if (705 <= moverRect.x && moverRect.x <= 785) {
                if ((moverRect.x - increment) < 705) {
                    return true;
                }
            }
        }

        //Region 8
        if (145 <= moverRect.y && moverRect.y <= 205) {
            if (59 <= moverRect.x && moverRect.x <= 134) {
                if ((moverRect.x - increment) < 59) {
                    return true;
                }
            }
        }

        //Region 7
        if (206 <= moverRect.y && moverRect.y <= 381) {
            if (881 <= moverRect.x && moverRect.x <= 881+75) {
                if ((moverRect.x - increment) < 881) {
                    return true;
                }
            }
        }

        //Region 9
        if (380 <= moverRect.y && moverRect.y <= 498) {
            if (59 <= moverRect.x && moverRect.x <= 134) {
                if ((moverRect.x - increment) < 59) {
                    return true;
                }
            }
        }

        //Region 10
        if (380 <= moverRect.y && moverRect.y <= 436) {
            if (352 <= moverRect.x && moverRect.x <= 427) {
                if ((moverRect.x - increment) < 352) {
                    return true;
                }
            }
        }

        //Region 11
        if (139 <= moverRect.y && moverRect.y <= 205) {
            if (763 <= moverRect.x && moverRect.x <= 838) {
                if ((moverRect.x - increment) < 763) {
                    return true;
                }
            }
        }

        //Region Water
        if (422-height <= moverRect.y && moverRect.y <= 541) {
            if (589 <= moverRect.x && moverRect.x <= 589+75) {
                if ((moverRect.x - increment) < 589) {
                    return true;
                }
            }
        }

        return false;

    } else if (d == 'R'){
        //Region 6,11,12,7,5,10

        //Region 5
        if (499 <= moverRect.y && moverRect.y <= 560) {
            if (820-75 <= moverRect.x && moverRect.x <= 820) {
                if ((moverRect.x + width + increment) > 820) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region 6
        if (0 <= moverRect.y && moverRect.y <= 148) {
            if (512 <= moverRect.x && moverRect.x <= 587) {
                if ((moverRect.x + width + increment) > 587) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region 7
        if (206 <= moverRect.y && moverRect.y <= 381) {
            if (706-75 <= moverRect.x && moverRect.x <= 706) {
                if ((moverRect.x + width + increment) > 706) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region 10
        if (380 <= moverRect.y && moverRect.y <= 443) {
            if (293-75 <= moverRect.x && moverRect.x <= 293) {
                if ((moverRect.x + width + increment) > 293) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region 11
        if (139 <= moverRect.y && moverRect.y <= 205) {
            if (706-75 <= moverRect.x && moverRect.x <= 706) {
                if ((moverRect.x + width + increment) > 706) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region 12
        if (149 <= moverRect.y && moverRect.y <= 498) {
            if (940-75 <= moverRect.x && moverRect.x <= 940) {
                if ((moverRect.x + width + increment) > 940) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        //Region Water
         if (422-height <= moverRect.y && moverRect.y <= 541) {
            if (467-75 <= moverRect.x && moverRect.x <= 467) {
                if ((moverRect.x + width + increment) > 467) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
}

void Player::move_up(){

        if (mov_up == 0) { 
            srcRect = {421,889,85,90};
            mov_up+=1; //increment counter
        } else if (mov_up == 1) {
            srcRect = {329,891,86,88};  
            mov_up+=1; //increment counter
        } else if (mov_up == 2) {
            srcRect = {511,891,87,88}; 
            mov_up=0; //reset counter
        }
    if ((wall_collision('U') == false)){
        moverRect.y-=6;
    }
}
void Player::move_down(){
    

        if (mov_down == 0) { 
            srcRect = {421,602,85,91};
            mov_down+=1; //increment counter
        } else if (mov_down == 1) {
            srcRect = {330,604,85,89};  
            mov_down+=1; //increment counter
        } else if (mov_down == 2) {
            srcRect = {511,604,85,89}; 
            mov_down=0; //reset counter
        }

    if ((wall_collision('D') == false)){
        moverRect.y+=6;
    }
}
void Player::move_left(){

        if (mov_left == 0) { 
            srcRect = {427,697,70,90};
            mov_left+=1; //increment counter
        } else if (mov_left == 1) {
            srcRect = {336,697,71,90};  
            mov_left+=1; //increment counter
        } else if (mov_left == 2) {
            srcRect = {517,697,71,90}; 
            mov_left=0; //reset counter
        }

    if ((wall_collision('L') == false)){
        moverRect.x-=6;
    }
}

void Player::move_right(){

        if (mov_right == 0) { 
            srcRect = {427,791,70,93};
            mov_right+=1; //increment counter
        } else if (mov_right == 1) {
            srcRect = {336,792,71,92};  
            mov_right+=1; //increment counter
        } else if (mov_right == 2) {
            srcRect = {517,791,71,93}; 
            mov_right=0; //reset counter
        }

    if ((wall_collision('R') == false)){
        moverRect.x+=6;
    }
}


Player* Player::getInstance() {

    
    if (instance == NULL) instance = new Player;

    return instance;
}

Player* Player::instance = NULL;