#include "CastleRaider.hpp"
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

void CastleRaider::drawObjects(){
    S_vec[0]->draw(gRenderer, assets);
    S_vec[0]->toggle();

    G_vec[0].draw(gRenderer, assets);

    K_vec[0]->draw(gRenderer, assets);
    //K_vec[0].hide_toggle();

    //T_vec[0].draw(gRenderer, assets);
    //T_vec[0].toggle_tres();
    treasure[0]->draw(gRenderer, assets);

    Tg_vec[0].draw(gRenderer, assets);
    //Tg_vec[0].Open();

    G_vec[0].draw(gRenderer, assets);

    lev[0]->draw(gRenderer, assets);
    //lev[0].rotate();

    Gu_vec[0].draw(gRenderer, assets);
    Gu_vec[0].patrol();

    health.draw(gRenderer, assets);

    

    // if (gamestate == WON) {

    //     display.draw(gRenderer, assets);
    //     display.Win();
    // }

    // if (gamestate == LOST) {

    //     display.draw(gRenderer, assets);
    //     display.Lose();
    // }



    for (std::list<Decoration*>::iterator fire=F_list.begin(); fire != F_list.end(); fire++) {
        (*(fire))->draw(gRenderer, assets);
        (*(fire))->place();
        
    }
    
    for (std::list<Decoration*>::iterator sk=S_list.begin(); sk != S_list.end(); sk++) {
        //(*(sk))->get_object(); 
        (*(sk))->draw(gRenderer, assets);
        (*(sk))->place();
    }

    for (std::list<Decoration*>::iterator pot=P_list.begin(); pot != P_list.end(); pot++) { 
        //(*(pot))->get_object();
        (*(pot))->draw(gRenderer, assets);
        (*(pot))->place();
    }

    for (std::list<Decoration*>::iterator drum=D_list.begin(); drum != D_list.end(); drum++) {
        //(*(drum))->get_object(); 
        (*(drum))->draw(gRenderer, assets);
        (*(drum))->place();
    }

    P1->draw(gRenderer, assets);


}

void CastleRaider::createObject(){
    // Spikes S1(290,480);   
    // S_vec.push_back(S1);
    S_vec.push_back(Prototype_Factory::make_object("Spikes"));        

    // Treasure_key K1(190,440);
    // K_vec.push_back(K1);
    K_vec.push_back(Prototype_Factory::make_object("T_key"));
     

    // Treasure T1(880, 195);
    // T_vec.push_back(T1); 

    treasure.push_back(Prototype_Factory::make_object("Treasure"));

    // Lever L1(360, 170);
    // lev.push_back(L1);
    lev.push_back(Prototype_Factory::make_object("Lever"));

    Guard Gu1(405,485);
    Gu_vec.push_back(Gu1);

    

    Treasure_Gate TG1(883,270);
    Tg_vec.push_back(TG1);

    Main_Gate G1(470, 40);  
    G_vec.push_back(G1);

    //health = {50,50};

    
    for(int i = 0; i < 2; i++) {

        if (i == 0) {
            Factory sk; //= new Factory("Skull",75, 200);
            Decoration* obj_sk = sk.create("Skull",75, 200);
            S_list.push_back(obj_sk);
            Factory dr; // = new Factory("Drum",600, 470, '1');
            Decoration* obj_dr = dr.create("Drum",600, 470, '1');
            D_list.push_back(obj_dr);
            Factory fr; //= new Factory("Fire",200, 100);
            Decoration* obj_fr = fr.create("Fire",200, 100);
            F_list.push_back(obj_fr);
            Factory pt; //= new Factory("Pot",70, 440,'1');
            Decoration* obj_pt = pt.create("Pot",70, 440,'1');
            P_list.push_back(obj_pt);

        }

        else
        {   
            Factory sk2; //= new Factory("Skull",780, 195);
            Decoration* obj_sk2 = sk2.create("Skull",780, 195);
            S_list.push_back(obj_sk2);
            Factory dr2; //= new Factory("Drum",820, 400, '3');
            Decoration* obj_dr2 = dr2.create("Drum",820, 400, '3');
            D_list.push_back(obj_dr2);
            Factory dr3; //= new Factory("Drum",610, 150, '2');
            Decoration* obj_dr3 = dr3.create("Drum",610, 150, '2');
            D_list.push_back(obj_dr3);
            Factory fr2; //= new Factory("Fire",880, 100);
            Decoration* obj_fr2 = fr2.create("Fire",880, 100);
            F_list.push_back(obj_fr2);
            Factory fr3; //= new Factory("Fire",200, 330);
            Decoration* obj_fr3 = fr3.create("Fire",200, 330);
            F_list.push_back(obj_fr3);
            Factory pt2; //= new Factory("Pots",110, 420,'2');
            Decoration* obj_pt2 = pt2.create("Pot",110, 420,'2');
            P_list.push_back(obj_pt2);
        }
        
    }

    // Player P1(740,490);
    // P_vec.push_back(P1);
                 
   
}
bool CastleRaider::object_collision(){

    for (std::list<Decoration*>::iterator pot=P_list.begin(); pot != P_list.end(); pot++) { 
        const SDL_Rect pott = (*(pot))->get_Object();
        if (SDL_HasIntersection(&temp, &pott) == true) {
           return true;
        }
    }

    for (std::list<Decoration*>::iterator drum=D_list.begin(); drum != D_list.end(); drum++) {
        const SDL_Rect drumm = (*(drum))->get_Object();
        if (SDL_HasIntersection(&temp, &drumm) == true) {
           return true;
        }
    }
    return false;

}

void CastleRaider::Hero(string direction, bool interact) {

    const SDL_Rect hero = P1->getPosition();
    const SDL_Rect key = K_vec[0]->get_item();
    const SDL_Rect treas = treasure[0]->get_item();
    const SDL_Rect lever = lev[0]->get_item();
    const SDL_Rect t_gate = Tg_vec[0].get_TGate();
    const SDL_Rect M_gate = G_vec[0].get_main();
    const SDL_Rect guard = Gu_vec[0].get_guard();
    const SDL_Rect spike = S_vec[0]->get_item();

    if (SDL_HasIntersection(&hero, &t_gate) == true && Tg_vec[0].Is_Open() == false) {


        if (direction == "down") P1->move_down();

        else if (direction == "right") P1->move_right();

        else if (direction == "left") P1->move_left();
    } 
    
    else if (SDL_HasIntersection(&hero, &M_gate) == true && G_vec[0].is_open() == false){


        if (direction == "down") P1->move_down();

        else if (direction == "right") P1->move_right();

        else if (direction == "left") P1->move_left();
    }

    else {

        // else if ((wall_collision('U') == false)){
        // moverRect.y-=6;
        temp = P1->getPosition();
        if (direction == "up") {
            temp.y-=3; 
            if (object_collision() == false) {
                P1->move_up();         
            } else {
                temp.y+=3;
            }
            
        }

        else if (direction == "down") {
            temp.y+=3; 
            if (object_collision() == false) {
                P1->move_down();         
            } else {
                temp.y-=3;
            }
        }

        else if (direction == "right") {
            temp.x+=3; 
            if (object_collision() == false){
                P1->move_right();      
            } else {
                temp.x-=3;
            }
        }

        else if (direction == "left") {
            temp.x-=3; 
            if (object_collision() == false) {
                P1->move_left();   
            } else {
                temp.x+=3;
            }
        }
    }


    keys.LoadSoundEffect("key.mp3");
    hurt.LoadSoundEffect("hurt.mp3");
    gate.LoadSoundEffect("gate.mp3");
    chest.LoadSoundEffect("treasure.mp3");


    if (SDL_HasIntersection(&hero, &key)) {
        if ((K_vec[0])->hide == false){
                keys.playSoundEffect();
            } 
        
            K_vec[0]->toggle();
            Tg_vec[0].Open();

        }

    

    if (SDL_HasIntersection(&hero, &treas) && interact == true) {
        if (treasure[0]->access == false){
                chest.playSoundEffect();
            } 
            //T_vec[0].toggle_tres();
            treasure[0]->toggle();
                    
        }
    


    if (SDL_HasIntersection(&hero, &lever) == true && treasure[0]->is_interacted() == true && interact == true) {
        if (lev[0]->escape == false){
                gate.playSoundEffect();
                
            }
        
            lev[0]->toggle();
            G_vec[0].Open();        
        }
        

    if (SDL_HasIntersection(&hero, &guard)) {
        hurt.playSoundEffect();
        
        health.bar();

        if (health.is_dead()) {

            gamestate = LOST;

            Game_Flag = true;
        }
    }


    if (SDL_HasIntersection(&hero, &spike) && S_vec[0]->is_interacted()) {
        hurt.playSoundEffect();

        health.bar();

        if (health.is_dead()) {

            gamestate = LOST;

            Game_Flag = true;
        }
    }

    

    if (hero.y <= 100) {

        gamestate = WON;
        
        Game_Flag = true;
    } 

}

void CastleRaider::display_state() {

    if (gamestate == WON) {

        display.draw(gRenderer, assets);
        display.Win();
    }

    if (gamestate == LOST) {

        display.draw(gRenderer, assets);
        health.bar();
        health.draw(gRenderer, assets);
        display.Lose();
    } 
}

ostream& operator << (ostream& out, const CastleRaider& C) {

    out<<"x_pos: "<<C.P1->getPosition().x<<" y_pos: "<<C.P1->getPosition().y;
    //out<<"collide check x_pos: "<<temp.x<<"collide check y_pos: "<<temp.y;

    return out;
}
CastleRaider::CastleRaider(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}

void CastleRaider::destroy_objects() {
 
    delete (P1);
    delete (treasure[0]);
    treasure.clear();
    delete (S_vec[0]);
    S_vec.clear();
    delete (K_vec[0]);
    K_vec.clear();
    delete (lev[0]);
    lev.clear();
 
    for (std::list<Decoration*>::iterator fire=F_list.begin(); fire != F_list.end(); fire++) { 
        delete (*(fire));
        (*(fire)) = NULL; 
    }
 
    F_list.clear();
    
    for (std::list<Decoration*>::iterator sk=S_list.begin(); sk != S_list.end(); sk++) { 
        delete (*(sk));
        (*(sk)) = NULL;
    }
 
    S_list.clear();
 
    for (std::list<Decoration*>::iterator pot=P_list.begin(); pot != P_list.end(); pot++) { 
        delete (*(pot));
        (*(pot)) = NULL;
    }
 
    P_list.clear();
 
    for (std::list<Decoration*>::iterator drum=D_list.begin(); drum != D_list.end(); drum++) { 
        delete (*(drum));
        (*(drum))= NULL;
    }
 
    D_list.clear();   
 
}