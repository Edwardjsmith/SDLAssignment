#include "entity.h"



entity::entity(const char* filename, int x, int y)
{
		setActive(true);

		m_entityTexture = textureManager::load(filename);

		m_xpos = x;
		m_ypos = y;

		srcRect.h = spriteHeight;
		srcRect.w = spriteWidth;
		srcRect.x = 0;
		srcRect.y = 0;

		destRect.x = x;
		destRect.y = y;
		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
	
		destRect.x = m_xpos;
		destRect.y = m_ypos;

	
		
}

void entity::render(int camX, int camY, SDL_RendererFlip flip)
{
	SDL_Rect draw{ m_xpos -= camX, m_ypos -= camY, destRect.w, destRect.h };

	SDL_RenderCopyEx(game::m_renderer, m_entityTexture, &srcRect, &draw, NULL,NULL, flip);
}

entity::~entity()
{
}


/*Mainly applies the gravity and resets jump. Since it's in the entity base class, it will apply
this to any class derived from this. This is how I have managed to apply gravity to both player and enemy
without duplicating code*/

void entity::update()
{

	if (hasCollided == false)
	{
		setY(4);
		speed = 2.0f;
	}

	if (canJump)
	{
		velocity = 0;
		gravity = 0;
		hasCollided = false;
	}




	if (m_jumping)
	{
		
		//srcRect.x = 64;
		canJump = false;
		gravity = (gravity + acceleration * delta) + (velocity + jumpPower * delta);


		if (jumpPower < 0)
		{
			jumpPower += 5;
		}
		if (jumpPower >= 0)
		{
			jumpPower = 0;
			isFalling = true;

		}
		if (int(round(gravity)) >= 1)
		{
			gravity = 1.0f; 
		}
		setY(int(round(gravity))); //Applies gravity
	}
	if (isFalling)
	{
		if (hasCollided == true)
		{
			setY(-2);//Fixes a bug where the sprite will sink through floor slightly
			m_jumping = false; //Essentially turns off grav when an entity is touching the floor
			jumpPower = -120; //resets jumpPower
			isFalling = false; //resets falling
			canJump = true; //Allows us to jump again
			hasCollided = false; //resets has collided
		}

	}

	
}
	




void entity::jump()
{
	m_jumping = true;
		
}

void entity::doubleJump()
{
	if (m_jumping == true && m_doubleJump == false)
	{
		{
			m_doubleJump = true;

			if (m_doubleJump)
			{
				
			}

		}
	}
}


void entity::move_left()
{
	setX(int(-speed));
}

void entity::move_right()
{
	setX(int(speed));
	//srcRect.x = 32;
}










