/* Header file for a base Sprite class, inherited by any class or object that is drawn to screen
* author CRoope 20/11/2009
* version 0.2 26/11/2009
*/
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>
#include <vector>
#include <stdlib.h>
#include "include/SDL.h"

using namespace std;

class Sprite {

public:
	Sprite();
	~Sprite();
	void draw(SDL_Surface *img, int x, int y);
	void draw(SDL_Surface *img, int x, int y,
                                int w, int h, int x2, int y2);

};

#endif