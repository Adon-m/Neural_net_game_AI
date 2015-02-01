
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Card.h"
#include "player.h"
#include "axum.h"
extern SDL_Surface *screen;
extern SDL_Surface *deck;
extern SDL_Event event;

bool quit= false;
int main( int argc, char* argv[] )
{
	Init();
	start();
		
	while (quit==false)
	{
		
	
	while( SDL_PollEvent( &event ) )
        {
		positionCards();	
            handleEvents();
				
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
	
	SDL_Flip(screen);
	
	}
	return 0;
}

