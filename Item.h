/* Header file for item class
* Author: CRoope 20/11/2009
* Version: 0.2 26/11/2009
*/
#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_opengl.h"

using namespace std;

class Item {

private:
	string name;
	enum effect {
		BOMB,
		SLOW,
		FAST,
		LOSELIFE };
	effect itemType;

	public:
	Item (string _name);
	Item (string _name, effect _type);
	~Item();
	string getName();
};

#endif