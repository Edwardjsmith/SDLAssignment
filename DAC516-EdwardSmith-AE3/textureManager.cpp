#include "textureManager.h"

SDL_Texture * textureManager::load(const char * filename)
{
	SDL_Surface* tempSurface = SDL_LoadBMP(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(game::m_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}

void textureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(game::m_renderer, texture, &src, &dest);
}


textureManager::textureManager()
{
}


textureManager::~textureManager()
{
}

