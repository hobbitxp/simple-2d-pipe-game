#include <string>
#include <stdlib.h>
#include "include/SDL.h"
#include "include/SDL_opengl.h"
#include "Enemy.h"

using namespace std;

Enemy::Enemy(string _name, Ai _aiType) : name(_name), aiType(_aiType) {}

string Enemy::getName() {
		return name;
	}
/*
Ai Enemy::getAi() {
		return aiType;
	}

void Enemy::setAI(Ai _aiType) {
		aiType = _aiType;
	}
	*/