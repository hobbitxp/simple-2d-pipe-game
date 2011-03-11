/* Class for Pipe objects
* author: CRoope 20/11/2009
* version: 0.8 5/12/2009
* All methods written by Chris Roope
* inherits from Sprite class
* Pipe object is a pickup for player, the player will pick up either a horizontal or vertical pipe
* They will then place it on the end of the pipe chain to direct flow of water
* 5/12: Player can only place pipes
* Pipes are stored in a randomly populated vector within the game class and taken from the end.
*/
#include <string>
#include <stdlib.h>
#include "include/SDL.h"
#include "Pipe.h"

using namespace std;

//Method to create a pipe
//Define type, either side or up.
//Load the correct image, then draw the pipe
Pipe::Pipe(string _type) : Sprite(), type(_type) {
	isLocked = false;
}

Pipe::~Pipe() {}

//Lock a pipe to a position, locked pipes cannot be moved
//Once the player places a pipe in the grid the pipe will be locked
void Pipe::lockPipe() {
	isLocked = true;
}

//return the type of a pipe
string Pipe::getType() {
	return type;
}
