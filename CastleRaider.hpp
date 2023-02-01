#pragma once
#include<SDL.h>
#include "Spikes.hpp"
#include "Treasure_key.hpp"
#include "Treasure.hpp"
#include "fire.hpp"
#include "Main_Gate.hpp"
#include "Treasure_Gate.hpp"
#include "Skull.hpp"
#include "Pots.hpp"
#include "Drums.hpp"
#include "Lever.hpp"
#include "Player.hpp"
#include "Guard.hpp"
#include "Display.hpp"
#include "Health.hpp"
#include "Factory.hpp"
#include "Decoration.hpp"
#include "Prototype_Factory.hpp"
#include "Prototype.hpp"
#include "sound.hpp"

#include <string>
#include <vector>
#include <list>

using namespace std;

class CastleRaider{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    // int p = 0; int eg= 0; int Ne = 0;       // Counters initialized to count number of objects that need to be drawn on the screen.
    vector <Prototype*> S_vec;                  // we create three vectors for the objects that are present in our game. (bird, nest, pigeon)
    vector <Prototype*> K_vec;                     
    vector <Prototype*> treasure;
    vector <Treasure_Gate> Tg_vec;
    vector <Main_Gate> G_vec;
    vector <Prototype*> lev;
    Player* P1 = Player::getInstance();
    SDL_Rect temp;

    vector <Guard> Gu_vec;
    
    list <Decoration*> F_list;
    list <Decoration*> S_list;
    list <Decoration*> D_list;
    list <Decoration*> P_list;

   
    Display display;
    Health health = {50,20};


       //sounds 
    SoundManager keys;
    SoundManager hurt;
    SoundManager gate;
    SoundManager chest;

    


    enum State {WON, LOST};
    State gamestate;

    public:
    CastleRaider(SDL_Renderer *, SDL_Texture *);
    bool Game_Flag = false;
    void drawObjects(); 
    void createObject();
    void display_state();
    void destroy_objects();
    bool object_collision();
    void Hero(string direction, bool interact);
    friend ostream& operator << (ostream& out, const CastleRaider& C);

    // ~CastleRaider();
};