#pragma once
#include "entity.h"
#include <iostream>

class command
{
public:
	Mix_Chunk* up, *left, *right;

	
	virtual void execute(entity& Entity) = 0;
	virtual ~command() {};
};

class doubleJumpCommand : public command
{
public:
	virtual void execute(entity& Entity){ Entity.doubleJump(); }

};
class jumpCommand : public command
{
public:
	virtual void execute(entity& Entity) {Entity.jump(); 
	}
	
};
class leftCommand : public command
{
public:
	virtual void execute(entity& Entity) 
	{ 
		Entity.move_left();
		game::flipType = SDL_FLIP_HORIZONTAL;
	}
	
};
class rightCommand : public command
{
public:
	virtual void execute(entity& Entity)
	{ 
		Entity.move_right(); 
		game::flipType = SDL_FLIP_NONE;
	}
	
};
class quitCommand : public command
{
public:
	virtual void execute(entity& Entity) { game::updateRunning(false); }

};




