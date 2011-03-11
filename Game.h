/* Header file for game class
* Author: CRoope 20/11/2009
* Version: 0.8 5/12/2009
*/
#ifndef __GAME_H__
#define __GAME_H__

#include <stdlib.h>
#include <vector>
#include "include/SDL.h"
#include "Pipe.h"
#include "Image.h"
#include "Grid.h"
#include "Player.h"

//using namespace std;

class Game {
	
private:
	//initialise the pipes vector, all the SDL surfaces for images and the window
	vector <Pipe> pipes;
	SDL_Surface* sidePipeImg;
	SDL_Surface* upPipeImg;
	SDL_Surface* playerImg;
	SDL_Surface* tileImg;
	SDL_Surface* openRightTileImg;
	SDL_Surface* openLeftTileImg;
	SDL_Surface* openUpTileImg;
	SDL_Surface* openDownTileImg;
	SDL_Surface* player1Wins;
	SDL_Surface* player2Wins;
	SDL_Surface* gameOverImg;
	SDL_Surface* timeOver;
	Image window;

public:
	Game();
	~Game();
	void initImages();
	void drawGrid(Grid &grid, vector<vector<Tile>>* tiles);
	void createPipes();
	void setPipe(vector<vector<Tile>>* tiles, int x, int y);
	void cleanUp();
};

#endif