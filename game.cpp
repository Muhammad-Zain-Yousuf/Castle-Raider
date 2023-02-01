#include "game.hpp"
#include "Unit.hpp"
#include "CastleRaider.hpp"
#include <iostream>

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow( "Castle Raider", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}

			// loading media into various objects of different classes and customizing them
			start_menu.loadImage(gRenderer,"MainMenuBG.jpeg");
			start_menu.customize(gRenderer,0, 0,600,1000);

			pause_menu.loadImage(gRenderer, "FINALPAUSEM.png");
			pause_menu.customize(gRenderer,300,180, 325, 425);

			instr_menu.loadImage(gRenderer, "INSTRUCTIONS_bg.png");
			instr_menu.customize(gRenderer,0,0,600,1000);

			// sound.Soundeffects();
			bg_sound.LoadMusic("Raider.mp3");
			keys.LoadSoundEffect("key.mp3");
			press.LoadSoundEffect("click.mp3");
			pause_sound.LoadSoundEffect("pause.mp3");
		}	

		return success;
	}

}
bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("assets.png");
    gTexture = loadTexture("Map_modified.png");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic = Mix_LoadMUS( "Raider.mp3" );

	if(bgMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	CastleRaider castleRaider(gRenderer, assets);
	// Player player(gRenderer, assets);

	const int FPS = 60;
	const int frameDelay = 1000/FPS;

	uint32_t frameStart;
	int frameTime;

	


	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN)
        	{	
				std::string direction = "";
				bool interact = false;
				SDL_Keycode key = e.key.keysym.sym;

				switch(key)
				{
				case SDLK_UP:
					direction = "up";
				break;
				
				case SDLK_DOWN:
					direction = "down";
				break;

				case SDLK_RIGHT:
					direction = "right";
				break;

				case SDLK_LEFT:
					direction = "left";
				break;

				case SDLK_a:
					interact = true;
				break;
				}
				if (castleRaider.Game_Flag == true) break;
				castleRaider.Hero(direction, interact);
				cout << castleRaider << endl;
				
			}

			castleRaider.createObject();  // calling this to create our objects
			


			// On main menu
			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&  gameState == "NotRunning" && pause==false && instr==false)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
		
				// New Game
				if (xMouse > 10 && xMouse < 155 && yMouse > 205 && yMouse <275) {
					gameState = "Running";
				}

				// instructions
				else if (xMouse > 10 && xMouse < 230 && yMouse > 321 && yMouse < 384) {
					instr = true;
				}

				// Quit Game
				else if (xMouse > 10 && xMouse < 145 && yMouse > 430 && yMouse < 495) {
					quit = true;
				}
			}


			else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&  gameState == "NotRunning" && instr==true){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);

				if (xMouse > 776 && xMouse < 992 && yMouse > 487 && yMouse <576) {
					instr = false;
				}
			}


			
			else if (e.type == SDL_KEYDOWN && gameState == "Running") {
				if (e.key.keysym.sym == SDLK_p && pause==false){
					// pause screen
					pause_menu.show(gRenderer);
					SDL_RenderPresent(gRenderer);
					pause = true;
					pause_sound.playSoundEffect();
				}
 			}


			// On pause menu
			else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&  gameState == "Running" && pause==true)
			{
				
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);

				// back to main menu
				if (xMouse > 400 && xMouse < 629 && yMouse > 297 && yMouse <406) {
					gameState = "NotRunning";
					pause = false;
					press.playSoundEffect();
					// destroy all objects
				}
				// resume game
				else if (xMouse > 395 && xMouse < 625 && yMouse > 225 && yMouse < 281) {
					pause = false;
					press.playSoundEffect();
					
				}

				// std::cout<<xMouse<<endl; std::cout<<yMouse<<endl;
			}


		}

		//if (castleRaider.Game_Flag) break;

		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			Mix_PlayMusic( bgMusic, 2 );
		}

		
		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer

		//***********************draw the objects here********************
		bool stop = false;
		if (gameState=="Running" && pause == false && castleRaider.Game_Flag == false){
				
			castleRaider.drawObjects();
			SDL_RenderPresent(gRenderer);
			}

		else if (castleRaider.Game_Flag == true) {
			gameState = "NotRunning";	
			castleRaider.drawObjects();
			castleRaider.display_state();
			SDL_RenderPresent(gRenderer);
		}


		else if (gameState=="NotRunning" && pause == false && instr == true){
			instr_menu.show(gRenderer);
			SDL_RenderPresent(gRenderer);
			// instr = false;
			}

		else if (gameState=="NotRunning" && pause == false  && instr == false){
			start_menu.show(gRenderer);
			SDL_RenderPresent(gRenderer);

			}


		frameStart = SDL_GetTicks();
		SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	    
	}
			
}
