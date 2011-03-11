/* Code for grid class
* Author: CRoope 20/11/2009
* Version: 0.8 5/12/2009
* All methods written by Chris Roope
* A grid is made up of a 2d array of tiles, 1 grid is defined for each player
* player can only move within their given grid, and can move anywhere within it at all times
* Grid is 10 tiles high and 10 wide, each tile is 24 pixels so a grid is 240pixels square
* 2 grids will fit on the 640x480 screen leaving 80 pixels free at the top for status
*/
#include "Grid.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include "include/SDL.h"
#include "Tile.h"

using namespace std;

Grid::Grid(string _type) : type(_type) {
	//2/12: If player1 grid; set 0 xOffset, if Player2; set to 328(640-grid size(13x24))
		if (type == "player1") {
			xOffset = 0;
		} else if (type == "player2") {
			xOffset = 328;
		}
		//call the addtiles method to populate the grid with tiles
		addTiles();
	}

Grid::~Grid() {
	}

//method to return the fixed height of a grid
int Grid::getHeight() {
		return HEIGHT;
	}

//method to return the fixed wisth of a grid
int Grid::getWidth() {
		return WIDTH;
	}

//2/12: Add tiles to the grid starting at xOffset and yOffset. Increase each iteration by 24 as a tile is 24pixels.
//x and y positions are the location to draw each tile Image.
//i is the place in the first vector, increased by one after the second for loop finishes each time
void Grid::addTiles() {
	int i = 0;
	for (int x = xOffset; x<xOffset+320; x+=24) {
		tiles.push_back(vector<Tile>());
		for (int y = YOFFSET; y<YOFFSET+360; y+=24) {
			tiles[i].push_back( Tile(x, y));
			}
		i++;
		}
	}

//3/12: return a pointer to a vector of a vector of tiles for setting objects and drawing in Game
vector<vector<Tile>>* Grid::getTiles() {
	return &tiles;
} 