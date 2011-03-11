/* Class for drawing images to screen
* author: CRoope 2/12/2009
* version: 0.5 4/12/2009
* uses draw method from Cone3d SDL tutorial
* This method just initialises SDL and uses a draw method from cone3d tutorials for drawing images
*/
#include <string>
#include <vector>
#include <stdlib.h>
#include "SDL.h"
#include "Image.h"
#include "Game.h"

using namespace std;

Image::Image() {
	//initialise SDL video
	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );

	//Create the window, width, height, bpp, flag variable
	screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, SCREEN_BPP, 
		SDL_HWSURFACE | SDL_DOUBLEBUF );
	//Sets the caption of the window Icon(0)
	SDL_WM_SetCaption( "The Lodges", 0 );

	SDL_EnableKeyRepeat(200, 200);

	SDL_Surface* back = SDL_LoadBMP( "background.bmp" );
	draw(back, 0, 0);
}

Image::~Image() {}

//4/12: Method to return the screen SDL_Surface for drawing images to
SDL_Surface* Image::getScreen() {
	return screen;
}

//Method to draw a given image to the screen at the given co-ordinates
//Taken from Cone3d SDL tutorial
void Image::draw(SDL_Surface *img, int x, int y)
	{
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_BlitSurface(img, NULL, screen, &dest);
	}

	//Function to draw a given image on screen given co-orinates.
	//This also redraws a given amount of pixels around the image to deal with the movement
	//Method taken from Cone3d SDL tutorial
void Image::draw(SDL_Surface *img, int x, int y,
                                int w, int h, int x2, int y2)
	{
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_Rect dest2;
		dest2.x = x2;
		dest2.y = y2;
		dest2.w = w;
		dest2.h = h;
		SDL_BlitSurface(img, &dest2, screen, &dest);
	}