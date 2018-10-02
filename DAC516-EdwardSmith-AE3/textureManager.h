#pragma once
#include "game.h"
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


class textureManager
{
public:


	static SDL_Texture* load(const char* filename);
	static void draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);

	textureManager();
	~textureManager();

private:

	int m_xpos, m_ypos;
};
#endif