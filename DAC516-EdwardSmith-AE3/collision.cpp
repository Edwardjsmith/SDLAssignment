#include "collision.h"



collision::collision()
{
}


collision::~collision()
{
}

bool collision::collidesTop(entity& entA, entity& entB)
{
	if (entA.getX() >= entB.getX() && entA.getX() <= entB.getX() + entB.destRect.w //Top left
	&& entA.getY() >= entB.getY() && entA.getY() <= entB.getY() + entB.destRect.h)
	{
		//std::cout << "Top left collision!";

		entA.speed = 0.0f;
		entA.setX(2);
		entA.speed = 2.0f;
		return true;
	}
	if (entA.getX() + entA.destRect.w >= entB.getX() && entA.getX() <= entB.getX() + entB.destRect.w //Top right
		&& entA.getY() >= entB.getY() && entA.getY() <= entB.getY() + entB.destRect.h)
	
	{
		//std::cout << "Top right collision!";
		entA.speed = 0.0f;
		entA.setX(-2);
		entA.speed = 2.0f;
		return true;
	}

		return false;
	
}

bool collision::collidesBottom(entity  entA, entity  entB)
{
	if (entA.getY() + entA.destRect.h > entB.getY() && entA.getY() < entB.getY() + entB.destRect.h //Bottom left
		&& entA.getX() > entB.getX() && entA.getX() < entB.getX() + entB.destRect.w)
	{
		return true;
	}
	if (entA.getY() + entA.destRect.h > entB.getY() && entA.getY() < entB.getY() + entB.destRect.h//Bottom right
		&& entA.getX() + entA.destRect.w > entB.getX() && entA.getX() < entB.getX() + entB.destRect.w)
	{
		return true;
	}



	return false;
}

bool collision::collidesBottomFull(entity  entA, entity  entB)
{
	if (entA.getY() + entA.destRect.h > entB.getY() && entA.getY() < entB.getY() + entB.destRect.h //Bottom left
		&& entA.getX() > entB.getX() && entA.getX() < entB.getX() + entB.destRect.w || entA.getY() + entA.destRect.h > entB.getY() && entA.getY() < entB.getY() + entB.destRect.h//Bottom right
		&& entA.getX() + entA.destRect.w > entB.getX() && entA.getX() < entB.getX() + entB.destRect.w)
	{
		return true;
	}

	return false;
}
