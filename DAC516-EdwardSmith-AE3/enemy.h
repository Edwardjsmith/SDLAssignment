#pragma once
#include "entity.h"
class enemy :
	public entity
{
public:
	enemy(const char* filename, int x, int y);
	~enemy();

	
};

