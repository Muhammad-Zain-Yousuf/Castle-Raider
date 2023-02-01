#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "menu.hpp"
#include "sound.hpp"

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
    bool pause = false;
    bool instr = false;
    std::string gameState = "NotRunning";
    Menu start_menu;
    Menu pause_menu;
    Menu instr_menu;


    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    
    Mix_Music *bgMusic = NULL;

    //sounds 
    SoundManager keys;
    SoundManager press;
    SoundManager bg_sound;
    SoundManager pause_sound;



public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

