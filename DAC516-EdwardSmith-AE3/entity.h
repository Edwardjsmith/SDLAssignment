#pragma once
#include "textureManager.h"
#include "soundManager.h"

#ifndef ENTITY_H
#define ENTITY_H


class entity
{
public:
	entity(const char* filename, int x, int y);

	
	bool isActive;
	

	void render(int camX, int camY, SDL_RendererFlip flip);

	static const int spriteHeight = 32; //Sets the width and height of each entity and makes these sizes 
	static const int spriteWidth = 32;	//Availiable where needed due to being static
	~entity();

	SDL_Rect srcRect, destRect; //srcRect controls which frame is displayed while dest affects pos

	int getX() { return m_xpos; } //returns x, y pos' which are set to the destRect
	int getY() { return m_ypos; }


	int setX(int x){return m_xpos += x;}	//Gives the ability to affect the x, y pos'			
	int setY(int y){ return m_ypos += y;}

	void update();
	
	void jump();
	void doubleJump();

	

	void move_left();

	void move_right();
	

	void idle() {}

	//enum flip {SDL_HORIZONTAL_FLIP, SDL_FLIP_NONE};

	bool setActive(bool active)
	{
		return isActive = active;
	}

	bool setCollided(bool collide)
	{
		return hasCollided = collide;
	}

	
	float speed = 2.0f * delta;

protected:

	SDL_Texture* m_entityTexture;
	int m_xpos;
	int m_ypos;

	bool canJump = true;
	bool m_jumping = false;
	bool m_doubleJump;
	bool isFalling = false;

	bool hasCollided = false;


	float gravity = 0.0f;
	float acceleration = 4*9.81f;
	float jumpPower = -120.0f;
	float delta = 1.0f / 60.0f;
	float velocity = 0.0f;
	
	


private:



	

	







};
#endif