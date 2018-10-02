#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "textureManager.h"
#include "entity.h"
#include "gameObject.h"
#include "player.h"
#include "collision.h"
#include "enemy.h"
#include "input.h"
#include "command.h"

class level
{
public:
	
	
	int screenHeight = 0;
	int screenWidth = 0;

	level(std::string fileName, int sizeX, int sizeY, int screenW, int screenH);
	void render();

	void update();


	~level();

	bool returnPlayerCollision()
	{
		return collide;
	}

	bool checkLevel()
	{
		return nextLevel;
	}
	bool nextLevel = false;
private:

	bool collide = false;
	
	int monsterSpeed = -1;
	
	SDL_Rect m_src, m_dest;
	
	gameObject* finishLine;
	gameObject* pickMeUp;
	player* Player;
	std::vector<gameObject*>obj;
	std::vector<enemy*>Enemy;
	collision Collision;

	command* Command;
	input* Input;
	bool collectableCount = false;

	SDL_Rect camera;

};

