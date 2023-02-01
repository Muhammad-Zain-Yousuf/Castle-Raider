#include "Guard.hpp"
#include<string>
#include<iostream>

void Guard::patrol(){
    int movespeed = 5;

    if (moverRect.y==n1){
        srcRect = {130,887,85,92};
        turn = 0;
    }
    if (moverRect.y==n2 & turn==0){
        srcRect = {135,790,72,93};
        turn = 1;
    }
    if (moverRect.x==n3 & turn==1){
        srcRect = {135,697,72,88};
        turn = 2;
    }
    if (moverRect.x==n4 & turn==2){
        srcRect = {130,602,85,92};
        turn = 3;
    }

    else if (turn == 0)
    {
        if (animate == 0 || animate == 2) { 
            srcRect = {130,887,85,92};
            animate+=1;      //increment counter
        } else if (animate == 1) {
            srcRect = {221,890,87,89};   
            animate+=1;       //increment counter
        } else if (animate == 3) {
            srcRect = {35,887,89,92};
            animate=0;      //reset counter
        }
        moverRect.y-=movespeed;
    }

    else if (turn == 1)
    {
        if (animate1 == 0 || animate1 == 2) { 
            srcRect = {135,790,72,93};
            animate1+=1;      //increment counter
        } else if (animate1 == 1) {
            srcRect = {221,793,71,90};   
            animate1+=1;       //increment counter
        } else if (animate1 == 3) {
            srcRect = {44,790,71,93};
            animate1=0;      //reset counter
        }
        moverRect.x+=movespeed;
    }

    else if (turn == 2)
    {
        if (animate2 == 0 || animate2 == 2) { 
            srcRect = {135,697,72,88};
            animate2+=1;      //increment counter
        } else if (animate2 == 1) {
            srcRect = {227,697,71,88};   
            animate2+=1;       //increment counter
        } else if (animate2 == 3) {
            srcRect = {44,697,71,88};
            animate2=0;      //reset counter
        }
        moverRect.x-=movespeed;
    }

    else if (turn == 3)
    {
        if (animate2 == 0 || animate2 == 2) { 
            srcRect = {130,602,85,92};
            animate2+=1;      //increment counter
        } else if (animate2 == 1) {
            srcRect = {221,602,86,92};   
            animate2+=1;       //increment counter
        } else if (animate2 == 3) {
            srcRect = {38,604,86,90};
            animate2=0;      //reset counter
        }
        moverRect.y+=movespeed;
    }

  

}

Guard::Guard(int x, int y) { //Constructor with parameters x, y for initial location of Player

    x_pos = x;
    y_pos = y;

    srcRect = {130,887,85,92};  //Default sprite 1 -> set as off by default
    moverRect = {x_pos, y_pos, 50, 50}; //set Player at x_pos, y_pos on screen with size 40,40
}

SDL_Rect Guard::get_guard() {

    return moverRect;
    
}
