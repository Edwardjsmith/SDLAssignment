#pragma once
#include "entity.h"
class gameObject :
	public entity
{
public:
	gameObject(const char* filename, int x, int y);
	~gameObject();
};

