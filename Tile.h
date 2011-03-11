/* Header file for a base Tile class
* author CRoope 20/11/2009
* version 0.8 5/12/2009
*/
#ifndef __TILE_H__
#define __TILE_H__

#include <string>
#include <stdlib.h>
#include "SDL.h"
#include "Pipe.h"
#include "Sprite.h"

using namespace std;

class Tile : public Sprite {
	
private:
	const static int SIZE = 24;
	int xPos, yPos;
	string state;
	bool hasPlayer, hasPipe;
	string openDirection;

public:
	Tile(int x, int y);
	~Tile();
	void addPipe(Pipe pipe);
	bool isPlayer();
	bool isPipe();
	void setPlayer(bool _bool);
	void setPipe();
	void setState(string _state);
	void setOpen(string _direction);
	string getOpen();
	string getState();
	int getX();
	int getY();
};

#endif