#include "input.h"

input::input()
{	
	doubleJump = new doubleJumpCommand();
	jump = new jumpCommand();
	leftMove = new leftCommand();
	rightMove = new rightCommand();
	quit = new quitCommand();

	upSound = soundManager::Instance()->loadSound("Music/Voice_001.wav");
	leftSound = soundManager::Instance()->loadSound("Music/Voice_003.wav");
	rightSound = soundManager::Instance()->loadSound("Music/Voice_004.wav");
	
}

input::~input()
{
	if (jump)
	{
		delete jump;
		jump = nullptr;
	}
	if (doubleJump)
	{
		delete doubleJump;
		doubleJump = nullptr;
	}

	if (leftMove)
	{
		delete leftMove;
		leftMove = nullptr;
	}
	if (rightMove)
	{
		delete rightMove;
		rightMove = nullptr;
	}
	if (down)
	{
		delete down;
		down = nullptr;
	}
	if (idle)
	{
		delete idle;
		idle = nullptr;
	}
	if (quit)
	{
		delete quit;
		quit = nullptr;
	}
}


command* input::updateInput()
{

	if (game::event.type == SDL_KEYDOWN)
	{
		SDL_Keycode keyPressed = game::event.key.keysym.sym;

		switch (keyPressed)
		{

		case SDLK_SPACE:
			
			m_keysPressed[KEY_SPACE] = true;
			break;


		case SDLK_DOWN:
			m_keysPressed[KEY_DOWN] = true;
			break;


		case SDLK_LEFT:
			
			m_keysPressed[KEY_LEFT] = true;
			break;


		case SDLK_RIGHT:
			
			m_keysPressed[KEY_RIGHT] = true;
			break;

		case SDLK_UP:
			m_keysPressed[KEY_UP] = true;
			break;

		case SDLK_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = true;
			break;

		default: break;
		}


	}

	else if (game::event.type == SDL_KEYUP)
	{
		SDL_Keycode keyPressed = game::event.key.keysym.sym;

		switch (keyPressed)
		{
		case SDLK_SPACE:
			m_keysPressed[KEY_SPACE] = false;
			break;

		case SDLK_DOWN:
			m_keysPressed[KEY_DOWN] = false;
			break;

		case SDLK_LEFT:
			m_keysPressed[KEY_LEFT] = false;
			break;
		case SDLK_RIGHT:
			m_keysPressed[KEY_RIGHT] = false;
			break;

		case SDLK_UP:
			m_keysPressed[KEY_UP] = false;
			break;

		case SDLK_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = false;
			break;

		default: break;
		}

	}

		if (m_keysPressed[KEY_UP])
		{
			return doubleJump;
		}

		if (m_keysPressed[KEY_SPACE])
		{
			soundManager::Instance()->playSound(upSound);
			
			return jump;
		}

		if (m_keysPressed[KEY_DOWN])
		{
			return down;
		}
		if (m_keysPressed[KEY_LEFT])
		{
			soundManager::Instance()->playSound(leftSound);
			
			return leftMove;
		}
		if (m_keysPressed[KEY_RIGHT])
		{
			soundManager::Instance()->playSound(rightSound);
			
			return rightMove;
		}
		if (m_keysPressed[KEY_ESCAPE])
		{
			return quit;
		}

		
		return NULL;


	
}

