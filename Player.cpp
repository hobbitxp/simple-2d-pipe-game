/* Code for Player class
* Author: CRoope 11/11/2009
* Version 0.9 5/12/2009
* All methods written by Chris Roope except:
* "Handle input" and "move" methods taken from lazyfoo SDL tutorials: http://lazyfoo.net/SDL_tutorials/lesson16/index.php
*/
#include <string>
#include <vector>
#include <stdlib.h>
#include "SDL.h"
#include "Item.h"
#include "Player.h"

using namespace std;
	
//Player contructor, takes a name, sets a player at position 0,14 in the grid.
Player::Player(string playerName) : Sprite(), name(playerName) {
	setPosition(0,14);
//	player = SDL_LoadBMP( "player.bmp" );
//	draw(player, 0, 0);
}

Player::~Player() {}

//return the name of the player
string Player::getName() {
		return name;
	}

//return the x grid position of a player
int Player::getX() {
		return x;
	}

//return the y grid position of a player
int Player::getY() {
		return y;
	}

//add a life to the player
void Player::addLife() {
		lives += 1;
	}

//remove one life from the player
void Player::removeLife() {
		lives -= 1;
	}

void Player::addItem(Item item) {
		items.push_back(item);
	}

Item Player::getItems() {
		for (int i = 0; i<items.size(); i++) {
			return items[i];
		}
	}

//5/12: Added setPosition method that has a collision check to make sure the player is inside the grid
// The player position is a tile within a grid, the drawgrid method in game check if a tile has a player
// So the limits for a player position is the size of the grid in tiles 13x14, starting at 0,0
void Player::setPosition(int _x, int _y) {
	if (_x >=0 && _x <= 12) {
		x = _x;
	}
	if (_y >=0 && _y <=14) {
		y = _y;
	}
	}

//Method taken from the lazyfoo SDL tutorials: http://lazyfoo.net/SDL_tutorials/lesson16/index.php
void Player::handle_input() {

	SDL_Event event;

	if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;    
        }
    }

	//If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += DOT_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= DOT_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += DOT_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= DOT_WIDTH / 2; break;   
        }        
    }
}

//Method taken from the lazyfoo SDL tutorials: http://lazyfoo.net/SDL_tutorials/lesson16/index.php
void Player::move() {
	//Move the dot left or right
    x += xVel;
    
    //If the dot went too far to the left or right
    if( ( x < 0 ) || ( x + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= xVel;    
    }
    
    //Move the dot up or down
    y += yVel;
    
    //If the dot went too far up or down
    if( ( y < 0 ) || ( y + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= yVel;    
    }
}