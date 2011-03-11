/* Class for drawing sprites to screen
* author: CRoope 20/11/2009
* version: 0.2 26/11/2009
* uses draw method from Cone3d SDL tutorial
*/
#include <string>
#include <stdlib.h>
#include "SDL.h"
#include "Sprite.h"

using namespace std;

Sprite::Sprite() {}

Sprite::~Sprite() {}

//Method to draw a given image to the screen at the given co-ordinates
//Taken from Cone3d SDL tutorial http://cone3d.gamedev.net/cgi-bin/index.pl?page=tutorials/gfxsdl/tut2
void Sprite::draw(SDL_Surface *img, int x, int y)
	{
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
//		SDL_BlitSurface(img, NULL, screen, &dest);
	}

	//Function to draw a given image on screen given co-orinates.
	//This also redraws a given amount of pixels around the image to deal with the movement
	//Method taken from Cone3d SDL tutorial http://cone3d.gamedev.net/cgi-bin/index.pl?page=tutorials/gfxsdl/tut2
void Sprite::draw(SDL_Surface *img, int x, int y,
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
//		SDL_BlitSurface(img, &dest2, screen, &dest);
	}