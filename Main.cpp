/* Main method for 2dgame
* author: CRoope 05/11/2009
* version 0.6 26/11/2009
* code is mainly for initialising SDL, loading and displaying images and dealing with user input in the main game loop
* Most of the methods were taken from a mixture of moosader, lazyfoo, and cone3d SDL tutorials
* 4/12: Removed nearly all code from main method, it now just creates an instance of a game object
*
*/
#pragma comment(lib, "lib/SDL.lib")
#pragma comment(lib, "lib/SDLmain.lib")

#include <stdlib.h>
#include "include/SDL.h"
#include "Game.h"

int main(int argc, char **argv)
{
	Game* myGame = new Game();
	return 0;
}