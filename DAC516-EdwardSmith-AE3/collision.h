#pragma once
#include "entity.h"
#include <vector>

class collision
{
public:
	collision();
	~collision();

	bool collidesTop(entity& entA, entity& entB);
	bool collidesBottom(entity entA, entity entB);
	bool collidesBottomFull(entity entA, entity entB);
	//bool collidesBottom(entity& entA, entity& entB);
};

