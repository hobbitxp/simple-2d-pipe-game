/* Class for Tile objects
* author: CRoope 20/11/2009
* version: 0.8 6/12/2009
* all methods written by Chris Roope
* inherits from Sprite class
* Tile is an object to define the grid, a tile is 24x24 pixels, a player can place pipes in tiles
* 5/12: Added open state to know what tiles a new pipe can be placed.
* tiles to the left and right of a side pipe and above an up pipe are open.
* 
*/
#include <string>
#include <stdlib.h>
#include "include/SDL.h"
#include "Pipe.h"
#include "Tile.h"

using namespace std;

//Tile contructor, takes co-ordinates as a parameter
//set the hasPlayer and hadPipe to false, set state to "empty", set openDirection to closed
Tile::Tile(int x, int y) : Sprite(), xPos(x), yPos(y) {
	Tile::hasPlayer = false;
	Tile::hasPipe = false;
	setState("empty");
	Tile::openDirection = "closed";
}

Tile::~Tile() {}

//Add a pipe to a tile and set the state, either "Up" or "Side"
void Tile::addPipe(Pipe pipe) {
	setState(pipe.getType());
	Tile::hasPipe = true;
}

//Method to return value of isPlayer to check whether the player is in a tile for placing a pipe
bool Tile::isPlayer() {
	return hasPlayer;
}

//Method to check whether the tile has a pipe so the player can only lay one pipe in a tile
bool Tile::isPipe() {
	return hasPipe;
}

//set the state of the tile, either "empty", "side", "up" or "open
//5/12: If state isn't empty or open set the pipe attribute to "true"
void Tile::setState(string _state) {
	state = _state;
	if (_state != "empty" && _state != "open") {
		setPipe();
	}
}

//Set the pipe value to True, to use when adding a pipe
void Tile::setPipe() {
	hasPipe = true;
}

//Set player value to true when a player moves into a tile
void Tile::setPlayer(bool _bool) {
	hasPlayer = _bool;
}

//Set the tile open in a direction, for drawing open tiles at the start and end positions
void Tile::setOpen(string _direction) {
	openDirection = _direction;
}

//Get what direction the pipe is open in, for drawing the correct image
string Tile::getOpen() {
		return openDirection;
}

//return the state of the tile to evaluate whether player can place a pipe
//or what pipe the player can place next to it.
string Tile::getState() {
	return state;
}

//Get the actual x co-ordinate of the tile to know where on screen to draw it
int Tile::getX() {
	return xPos;
}

//Get the actual y co-ordinate of the tile to know where on screen to draw it
int Tile::getY() {
	return yPos;
}