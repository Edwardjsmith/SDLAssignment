#pragma once
#include "entity.h"
#include <stdio.h>

#ifndef PLAYER_H
#define PLAYER_H



class player :
	public entity
{
public:

	player(const char* filename, int x, int y );
	~player();


	//void render(int camX, int camY);
	
};
#endif
