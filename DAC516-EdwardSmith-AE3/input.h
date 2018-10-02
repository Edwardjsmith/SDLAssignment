#pragma once
#include "game.h"
#include "command.h"
#include "entity.h"

enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_SPACE, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_ESC, KEY_NUM_OF
};

class input
{

public:
	input();

	~input();

	

	
	command* updateInput();

private:

	bool m_keysPressed[KEY_NUM_OF];

	command* jump;
	command* leftMove;
	command* rightMove;
	command* down;
	command* idle;
	command* doubleJump;
	command* quit;

	Mix_Chunk *upSound, *leftSound, *rightSound;
	

};


