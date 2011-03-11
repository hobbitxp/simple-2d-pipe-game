/* Header file for a base Pipe class
* author CRoope 20/11/2009
* version 0.8 05/12/2009
*/
#ifndef __PIPE_H__
#define __PIPE_H__

#include <string>
#include <stdlib.h>
#include "include/SDL.h"
#include "Sprite.h"

using namespace std;

class Pipe : public Sprite {

private:
	string type;
	bool isLocked;
	SDL_Surface* pipeImg;
	int xPos, yPos;

public:
	Pipe(string _type);
	~Pipe();
	void lockPipe();
	string getType();
	void setPos();
};

#endif