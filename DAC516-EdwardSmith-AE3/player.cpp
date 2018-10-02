#include "player.h"
#include <iostream>


player::player(const char* filename, int x, int y) : entity::entity(filename, x, y)
{
}


player::~player()
{
}




/*void player::render(int camX, int camY)
{

	SDL_Rect draw{ m_xpos -= camX, m_ypos, destRect.w, destRect.h};

	SDL_RenderCopy(game::m_renderer, m_entityTexture, NULL , &draw);
}*/

