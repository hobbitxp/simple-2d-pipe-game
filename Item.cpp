#include <string>
#include <stdlib.h>
#include "include/SDL.h"
#include "include/SDL_opengl.h"
#include "Item.h"

using namespace std;

	Item::Item (string _name) : name(_name) {}
	Item::Item (string _name, effect _type) : name(_name), itemType(_type) {}
	Item::~Item() {}

	string Item::getName() {
		return name;
	}