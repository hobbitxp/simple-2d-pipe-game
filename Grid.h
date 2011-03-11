/* Header file for grid class
* Author: CRoope 20/11/2009
* Version: 0.8 5/12/2009
*/
#ifndef __GRID_H__
#define __GRID_H__

#include <string>
#include <vector>
#include <stdlib.h>
#include "include/SDL.h"
#include "Tile.h"

using namespace std;

class Grid {

private:
	string type;
	//2/12: make a grid 13 tiles wide (13x24pixels)
	//15 tiles high (15x24 pixels)
	//set yOffset to 60 so the grids are in the middle of the screen
	static const int WIDTH = 13;
	static const int HEIGHT = 15;
	static const int YOFFSET = 60;
	int xOffset;
	//2/12: create a vector of a vector of Tiles!
	vector<vector<Tile> > tiles;

public:
	Grid(string _type);
	~Grid();
	int getWidth();
	int getHeight();
	void addTiles();
	//3/12: return a pointer to the vector of a vector of Tiles
	vector<vector<Tile>>* getTiles();
};

#endif