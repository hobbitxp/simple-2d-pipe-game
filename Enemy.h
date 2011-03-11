#ifndef __ENEMY_H__
#define __ENEMY_H__

#include<string>
#include <stdlib.h>
#include "include/SDL.h"
#include "include/SDL_opengl.h"

using namespace std;

class Enemy {

private:
	string name;
	enum Ai { 
		FAST,
		SLOW,
		AGGRESSIVE,
		SPIRAL };
	Ai aiType;

public:
	Enemy(string _name, Ai _aiType);
	string getName();
/*	Ai getAi();
	void setAI(Ai _aiType);
*/
};

#endif