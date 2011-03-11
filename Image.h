/* Header file for a base Image class
* author CRoope 2/12/2009
* version 0.5 4/12/2009
*/
#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include <vector>
#include <stdlib.h>
#include "include/SDL.h"

using namespace std;

class Image {

private:
	const static int WINDOW_WIDTH = 640;
	const static int WINDOW_HEIGHT = 480;
	const static int SCREEN_BPP = 32;
	//Initialise the surfaces
	SDL_Surface* screen;

public:
	Image();
	Image(string name);
	~Image();
	SDL_Surface* getScreen();
	void draw(SDL_Surface *img, int x, int y);
	void draw(SDL_Surface *img, int x, int y,
                                int w, int h, int x2, int y2);

};

#endif