/* Header file for grid class
* Author: CRoope 20/11/2009
* Version: 0.8 5/12/2009
*/
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <vector>
#include <stdlib.h>
#include "include/SDL.h"
#include "Item.h"
#include "Sprite.h"

using namespace std;

class Player : public Sprite{

private:
	string name;
	int x, y;
	int xVel, yVel;
	int lives;
	vector <Item> items;
	static const int DOT_HEIGHT = 20;
	static const int DOT_WIDTH = 20;
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	SDL_Surface* player;
	
public:
	Player(string playerName);
	~Player();
	string getName();
	int getX();
	int getY();
	void addLife();
	void removeLife();
	void addItem(Item item);
	Item getItems();
	void move();
	void handle_input();
	void setPosition(int _x, int _y);
};

#endif